/*
 *  mruby => TECS brige
 *  
 *   Copyright (C) 2008-2012 by TOPPERS Project
 *--
 *   �嵭����Ԥϡ��ʲ���(1)(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *       ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *       �ȡ�
 *     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *         ��𤹤뤳�ȡ�
 *   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *       ���դ��뤳�ȡ�
 *  
 *   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *   ����Ǥ�����ʤ���
 *  
 *   $Id: $ 
 */

#ifndef TECSStruct_h__
#define TECSStruct_h__

#define MEMBER_GET_SET_INT( TAG, MEMBER, Type, TYPE )					\
	static mrb_value													\
	Struct_ ## TAG ## _ ## MEMBER ## _aget(mrb_state *mrb, mrb_value self)	\
	{																	\
		struct TAG *st = DATA_PTR( self );								\
		TYPE ## _t	val;												\
																		\
		val = st->MEMBER;												\
		VALCHECK_MRB_ ## Type( mrb, val );								\
		return mrb_fixnum_value( val );									\
	}																	\
																		\
	static mrb_value													\
	Struct_ ## TAG ## _ ## MEMBER ## _aset(mrb_state *mrb, mrb_value self)	\
	{																	\
		struct TAG *st = DATA_PTR( self );								\
		mrb_int	val;													\
																		\
		mrb_get_args(mrb, "i", &val );									\
																		\
		VALCHECK_ ## Type ( mrb, val );									\
		st->MEMBER = val;												\
																		\
		return self;													\
	}

#define MEMBER_GET_SET_FLOAT( TAG, MEMBER )								\
	static mrb_value													\
	Struct_ ## TAG ## _ ## MEMBER ## _aget(mrb_state *mrb, mrb_value self)	\
	{																	\
		struct TAG *st = DATA_PTR( self );								\
																		\
		return mrb_float_value( st->MEMBER );								\
	}																	\
																		\
	static mrb_value													\
	Struct_ ## TAG ## _ ## MEMBER ## _aset(mrb_state *mrb, mrb_value self)	\
	{																	\
		struct TAG *st = DATA_PTR( self );								\
		mrb_float	val;												\
																		\
		mrb_get_args(mrb, "f", &val );									\
																		\
		st->MEMBER = val;												\
																		\
		return self;													\
	}

////  define Struct class ////
#define STRUCT_CLASS( TAG )												\
																		\
	static void															\
	Struct ## TAG ## Body_free( mrb_state *mrb, void *p )				\
	{																	\
		(void)mrb_free( mrb, p );										\
	}																	\
																		\
	struct mrb_data_type Struct ## TAG ## Body_mrb_data_type =			\
		{																\
			"TECS::Struct" #TAG,										\
			Struct ## TAG ## Body_free									\
		};																\
																		\
	static mrb_value													\
	Struct_ ## TAG ## _initialize( mrb_state *mrb, mrb_value self)		\
	{																	\
		mrb_int	length;													\
		struct  TAG *structBody;										\
																		\
		DATA_TYPE( self ) = &Struct ## TAG ## Body_mrb_data_type;		\
		DATA_PTR( self ) = mrb_malloc(mrb, sizeof(struct TAG)); 		\
						 												\
		return self;													\
	}

#define  STRUCT_INIT_BEGIN( TAG )										\
	struct RClass *														\
	tecs_init_Struct_## TAG(mrb_state *mrb, struct RClass *TECS)		\
	{																	\
		struct RClass *a;												\
																		\
		a = mrb_define_class_under(mrb, TECS, "Struct" #TAG, mrb->object_class); \
		MRB_SET_INSTANCE_TT(a, MRB_TT_DATA);							\
																		\
		mrb_define_method(mrb, a, "initialize", Struct_ ## TAG ## _initialize,            ARGS_NONE());

#define  STRUCT_INIT_MEMBER( TAG, MEMBER )								\
		mrb_define_method(mrb, a, #MEMBER,      Struct_ ## TAG ## _ ## MEMBER ## _aget,   ARGS_NONE()); \
		mrb_define_method(mrb, a, #MEMBER "=",  Struct_ ## TAG ## _ ## MEMBER ## _aset,   ARGS_REQ(1));


#define  STRUCT_INIT_END( TAG )											\
	}

#define CHECK_STRUCT( tag, value )										\
	do {																\
		if( mrb_type(value) != MRB_TT_DATA								\
			|| DATA_TYPE( value ) == 0									\
			|| strcmp( DATA_TYPE( value )->struct_name, "TECS::Struct" #tag ) ) \
			mrb_raise(mrb, E_TYPE_ERROR, "not Struct or tag mismatch"); \
	}while(0)

#endif /* TECSStruct_h__ */
