/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007 by GJ Business Division RICOH COMPANY,LTD. JAPAN  
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id$
 */

/*
 *  ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�AT91SAM7S�ѡ�
 */

#include <kernel.h>
#include <t_syslog.h>
#include "at91sam7s.h"
#include "target_serial.h"

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block 
{
    void* uart_base;
    void* linectrl_pdr;
    uint32_t pdr_bit;
}
SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
struct sio_port_control_block 
{
    const SIOPINIB  *p_siopinib;  /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
    intptr_t  exinf;              /* ��ĥ���� */
    bool_t    openflag;           /* �����ץ�Ѥߥե饰 */
    bool_t    sendflag;           /* ��������ߥ��͡��֥�ե饰 */
    bool_t    getready;           /* ʸ��������������� */
    bool_t    putready;           /* ʸ���������Ǥ������ */
};

/*
 * ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
    {(void*)(TADR_DBGU_BASE),
     (void*)(TADR_PIO_BASE+TOFF_PIO_PDR),
     (uint32_t)(TOFF_PIO_PDR_VAL)
    }
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)  ((uint_t)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 * ʸ�������������?
 */ 
Inline bool_t
uart_getready(SIOPCB *p_siopcb)
{
    return(((sil_rew_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_CSR)) & US_RXRDY)!=0));
}

/*
 * ʸ���������Ǥ��뤫?
 */
Inline bool_t
uart_putready(SIOPCB *p_siopcb)
{
    return((sil_rew_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_CSR)) & US_TXEMPTY)!=0);
}

/*
 *  ��������ʸ���μ��Ф�
 */
Inline uint8_t
uart_getchar(SIOPCB *p_siopcb)
{
    return(sil_rew_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_RHR)));
}

/*
 *  ��������ʸ���ν񤭹���
 */
Inline void
uart_putchar(SIOPCB *p_siopcb, uint8_t c)
{
    sil_wrw_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_THR),c);
}

/*
 *  ��������ߵ���
 */
Inline void
uart_enable_send(SIOPCB *p_siopcb)
{
    sil_wrw_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_IER), US_TXEMPTY);
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_send(SIOPCB *p_siopcb)
{
    sil_wrw_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_IDR), US_TXEMPTY);
}


/*
 *  ��������ߵ���
 */
Inline void
uart_enable_rcv(SIOPCB *p_siopcb)
{
    sil_wrw_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_IER), US_RXRDY);
}

/*
 *  ��������߶ػ�
 */
Inline void
uart_disable_rcv(SIOPCB *p_siopcb)
{
    sil_wrw_mem((void*)(p_siopcb->p_siopinib->uart_base+TOFF_US_IDR), US_RXRDY);
}


/*
 *  SIO�ɥ饤�Фν����
 */
void
sio_initialize(intptr_t exinf)
{
    SIOPCB  *p_siopcb;
    uint_t  i;

    /*
     *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
     */
    for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
        p_siopcb->p_siopinib = &(siopinib_table[i]);
        p_siopcb->openflag = false;
        p_siopcb->sendflag = false;
    }
}

/*
 * ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
at91sam7s_uart_opn_por(SIOPCB *p_siopcb, intptr_t exinf)
{
    uint32_t baud = ((MCK * 10) / (BAUDRATE * 16));
    const SIOPINIB  *p_siopinib;
    p_siopinib = p_siopcb->p_siopinib;

    /* Disable Interrupt */
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_IDR), 0xFFFFFFFF);
           
    /* �������ػ� */
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_CR), (US_RSTRX|US_RSTTX|US_RXDIS|US_TXDIS));

    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_PDC_RCR), 0);
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_PDC_TCR), 0);
    
    /* PIOA��PA9,PA10��UART�ǻ��� */
    sil_wrw_mem((void*)p_siopinib->linectrl_pdr, p_siopinib->pdr_bit);
    
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_MR), (US_CLKS_MCK|US_CHRL_8|US_PAR_NO|US_NBSTOP_1|US_CHMODE_NORMAL));
    
    /* 115200bps */
    if((baud % 10) >= 5){
        sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_BRGR), (baud/10)+1);
    } else {
        sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_BRGR), (baud/10));
    }
    
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_TTGR), 0);
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_CR), US_TXEN|US_RXEN);
    
    sil_rew_mem((void*)(p_siopinib->uart_base+TOFF_US_RHR));

    /*
     *  �ܡ��졼���������Ԥ�
     */
    sil_dly_nse(200000);

    p_siopcb->exinf = exinf;
    p_siopcb->getready = p_siopcb->putready = false;
    p_siopcb->openflag = true;

    return(p_siopcb);
}


/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
    SIOPCB  *p_siopcb = get_siopcb(siopid);
    bool_t  opnflg;
    ER      ercd;

    /*
     *  �����ץ󤷤��ݡ��Ȥ����뤫��opnflg���ɤ�Ǥ�����
     */
    opnflg = p_siopcb->openflag;

    /*
     *  �ǥХ�����¸�Υ����ץ������
     */
    at91sam7s_uart_opn_por(p_siopcb, exinf);

    /*
     *  ���ꥢ��I/O����ߤΥޥ����������롥
     */
    if (!opnflg) {
        ercd = ena_int(INTNO_SIO);
        assert(ercd == E_OK);
    }
    return(p_siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
    /*
     *  �ǥХ�����¸�Υ�����������
     */
    const SIOPINIB  *p_siopinib;

    p_siopinib = p_siopcb->p_siopinib;
    sil_wrw_mem((void*)(p_siopinib->uart_base+TOFF_US_CR), US_RSTRX|US_RSTTX|US_RXDIS|US_TXDIS);
    p_siopcb->openflag = false;
    
    /*
     *  ���ꥢ��I/O����ߤ�ޥ������롥
     */
    dis_int(INTNO_SIO);    
}

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
void
sio_isr(intptr_t exinf)
{
    SIOPCB *p_siopcb = &(siopcb_table[0]);

    if (uart_getready(p_siopcb)) {
        /*
         *  �������Υ�����Хå��롼�����ƤӽФ���
         */
        sio_irdy_rcv(p_siopcb->exinf);
    }
    if (uart_putready(p_siopcb)) {
        /*
         *  ������ǽ������Хå��롼�����ƤӽФ���
         */
        sio_irdy_snd(p_siopcb->exinf);
    }    
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char_t c)
{
    if (uart_putready(siopcb)) {
        uart_putchar(siopcb, c);
        return(true);
    }
    return(false);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
sio_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((int_t)(uint8_t) uart_getchar(siopcb));
    }
    return(false);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
    switch (cbrtn) {
        case SIO_RDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_RDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
    switch (cbrtn) {
        case SIO_RDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_RDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}
