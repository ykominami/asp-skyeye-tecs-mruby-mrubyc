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
 *   $Id: TECSPointer.h 1887 2012-09-14 07:26:36Z okuma-top $ 
 */

#ifndef TECSPointer_h__
#define TECSPointer_h__

#include <string.h>
#include <stdint.h>
#include <limits.h>


#ifndef CHAR_T_DEFINED
/*typedef	int		bool_t;
typedef	char	char_t;
typedef	double	double64_t;
typedef	float	float32_t;*/
#endif /* CHAR_T_DEFINED */

////  define Pointer classes ////
#define POINTER_BODY( Type, TYPE )										\
																		\
	struct Type ## PointerBody {										\
		uint32_t	length;												\
		TYPE 		buf[ /* length */ ];								\
	};


// struct TypePointerBody
POINTER_BODY( Bool,  bool_t )		/* struct BoolPointerBody */
POINTER_BODY( Double64, double64_t )/* struct Double64PointerBody */
POINTER_BODY( Float32, float32_t )	/* struct Float32PointerBody */
POINTER_BODY( Int8,  int8_t )		/* struct Int8PointerBody */
POINTER_BODY( Int16, int16_t )		/* struct Int16PointerBody */
POINTER_BODY( Int32, int32_t )		/* struct Int32PointerBody */
POINTER_BODY( Int64, int64_t )		/* struct Int64PointerBody */
POINTER_BODY( Char,  char_t )		/* struct CharPointerBody */
POINTER_BODY( Int,   int )			/* struct IntPointerBody */
POINTER_BODY( Short, short )		/* struct ShortPointerBody */
POINTER_BODY( Long,  long )			/* struct LongPointerBody */

POINTER_BODY( UInt8,  uint8_t )		/* struct UInt8PointerBody */
POINTER_BODY( UInt16, uint16_t )	/* struct UInt16PointerBody */
POINTER_BODY( UInt32, uint32_t )	/* struct UInt32PointerBody */
POINTER_BODY( UInt64, uint64_t )	/* struct UInt64PointerBody */
//POINTER_BODY( UChar,  uchar_t )		/* struct UCharPointerBody */
POINTER_BODY( UInt,   unsigned int )	/* struct UIntPointerBody */
POINTER_BODY( UShort, unsigned short )	/* struct UShortPointerBody */
POINTER_BODY( ULong,  unsigned long )	/* struct ULongPointerBody */

//POINTER_BODY( SChar,  schar_t )		/* struct SCharPointerBody */

	 // �� TECS_NO_VAL_CHECK �� define ����ȡ��ͥ����å����ά����
#ifndef TECS_NO_VAL_CHECK
#define	VALCHECK_INT(Type, TYPE, type )									\
	/*  check before assigning mrb_int val to intN_t */					\
	static inline void													\
	VALCHECK_ ## Type( mrb_state *mrb, mrb_int val )					\
	{																	\
		if( sizeof( mrb_int ) > sizeof( type ) ){						\
			if( val > TYPE ## _MAX || val < TYPE ## _MIN ) 				\
				mrb_raise(mrb, E_ARGUMENT_ERROR, "too large or too small for "  #type "_t"); \
		}																\
	}
#define	VALCHECK_MRB_INT(Type, TYPE, type )								\
	/*  check before assigning val (intN_t) to mrb_int */				\
	static inline void													\
	VALCHECK_MRB_ ## Type( mrb_state *mrb, type val )					\
	{																	\
		if( sizeof( type ) > sizeof( mrb_int ) ){						\
			if( val >= (((type)1) << (sizeof(mrb_int)*8-1))				\
				|| val < -(((type)1) << (sizeof(mrb_int)*8-1)) )		\
				/* '=' unecessary for negative value	*/				\
				/* ignore warning on int32_t */							\
				mrb_raise(mrb, E_ARGUMENT_ERROR, "too large or too small for mrb_int"); \
		}																\
	}

#define	VALCHECK_UINT(Type, TYPE, type )								\
	/*  check before assigning mrb_int val to intN_t */					\
	static inline void													\
	VALCHECK_ ## Type( mrb_state *mrb, mrb_int  val )					\
	{																	\
		if( sizeof( mrb_int ) > sizeof( type ) ){						\
			if( val > TYPE ## _MAX || val < 0 ) 						\
				mrb_raise(mrb, E_ARGUMENT_ERROR, "too large or too small for "  #type "_t"); \
		}																\
	}
#define	VALCHECK_MRB_UINT(Type, TYPE, type )							\
	/*  check before assigning val (intN_t) to mrb_int */				\
	static inline void													\
	VALCHECK_MRB_ ## Type( mrb_state *mrb, type val )					\
	{																	\
		if( sizeof( type ) > sizeof( mrb_int ) ){						\
			if( val >= (((type)1) << (sizeof(mrb_int)*8)))				\
				/* '=' unecessary for negative value	*/				\
				/* ignore warning on int32_t */							\
				mrb_raise(mrb, E_ARGUMENT_ERROR, "too large or too small for mrb_int"); \
		}																\
	}
#else // TECS_NO_VAL_CHECK

#define	VALCHECK_INT(Type, TYPE, type )
#define	VALCHECK_UINT(Type, TYPE, type )

#endif // TECS_NO_VAL_CHECK

// define VALCHECK function
#define VALCHECK_Bool( mrb, val )
#define	VALCHECK_MRB_Bool( mrb, val )

VALCHECK_INT( Int8, INT8, int8_t )
VALCHECK_MRB_INT( Int8, INT8, int8_t )
VALCHECK_INT( Int16, INT16, int16_t )
VALCHECK_MRB_INT( Int16, INT16, int16_t )
VALCHECK_UINT( UInt8, UINT8, uint8_t )
#define	VALCHECK_MRB_UInt8
VALCHECK_UINT( UInt16, UINT16, uint16_t )
#define	VALCHECK_MRB_UInt16
VALCHECK_INT( Int32, INT32, int32_t )
#define VALCHECK_MRB_Int32
VALCHECK_UINT( UInt32, UINT32, uint32_t )
#define VALCHECK_MRB_UInt32

VALCHECK_INT( Int64, INT64, int64_t )
VALCHECK_UINT( UInt64, UINT64, uint64_t )
#ifndef mrb_int_IS_int64
	 // �� int 32 bit ���ꤷ�Ƥ���. 64 bit �Ǥ���� mrb_int_IS_64 �� define ����
VALCHECK_MRB_INT( Int64, INT64, int64_t )
VALCHECK_MRB_UINT( UInt64, UINT64, uint64_t )
#else
#define VALCHECK_MRB_Int64      // �ϰϥ����å���̵��̣�Ǥ��뤿�ᡢ�ٹ𤬽Ф�Τ���򤹤�
#define VALCHECK_MRB_UInt64      // �ϰϥ����å���̵��̣�Ǥ��뤿�ᡢ�ٹ𤬽Ф�Τ���򤹤�
#endif

#ifndef TECS_NO_VAL_CHECK
	 // �� char_t �� unsigned �Ȥߤʤ�
static inline void
VALCHECK_Char( mrb_state *mrb, mrb_int  val )
{
	if( val > 0xff || val < 0 )	
		mrb_raise(mrb, E_ARGUMENT_ERROR, "too large or too small for char_t");
}
#define	VALCHECK_MRB_Char( mrb, val )

VALCHECK_INT( Short, SHRT, short )
#define	VALCHECK_MRB_Short( mrb, val )

VALCHECK_INT( Int, INT, int )
#define	VALCHECK_MRB_Int( mrb, val )

VALCHECK_INT( Long, LONG, long )
#define	VALCHECK_MRB_Long( mrb, val )

VALCHECK_INT( SChar, SCHAR, signed char )
#define	VALCHECK_MRB_SChar( mrb, val )

VALCHECK_UINT( UChar, UCHAR, unsigned char )
#define	VALCHECK_MRB_UChar( mrb, val )

VALCHECK_UINT( UInt, UINT, unsigned int )
#define	VALCHECK_MRB_UInt( mrb, val )

VALCHECK_UINT( UShort, USHRT, unsigned short )
#define	VALCHECK_MRB_UShort( mrb, val )

VALCHECK_UINT( ULong, ULONG, unsigned long )
#define	VALCHECK_MRB_ULong( mrb, val )

#else // TECS_NO_VAL_CHECK

#define VALCHECK_Char( mrb, val )
#define	VALCHECK_MRB_Char( mrb, val )
#define VALCHECK_Int( mrb, val )
#define	VALCHECK_MRB_Int( mrb, val )
#define	VALCHECK_Short( mrb, val )
#define	VALCHECK_MRB_Short( mrb, val )
#define	VALCHECK_Long( mrb, val )
#define	VALCHECK_MRB_Long( mrb, val )
#define	VALCHECK_SChar( mrb, val )
#define	VALCHECK_MRB_SChar( mrb, val )
#define	VALCHECK_UChar( mrb, val )
#define	VALCHECK_MRB_UChar( mrb, val )
#define	VALCHECK_UInt( mrb, val )
#define	VALCHECK_MRB_UInt( mrb, val )
#define	VALCHECK_UShort( mrb, val )
#define	VALCHECK_MRB_UShort( mrb, val )
#define	VALCHECK_ULong( mrb, val )
#define	VALCHECK_MRB_ULong( mrb, val )

#endif // TECS_NO_VAL_CHECK

#define CHECK_POINTER( Type, value, len )								\
	do {																\
		if( mrb_type(value) != MRB_TT_DATA								\
			|| DATA_TYPE( value ) == 0									\
			|| strcmp( DATA_TYPE( value )->struct_name,  "TECS::" #Type "Pointer" ) ) \
			mrb_raise(mrb, E_TYPE_ERROR, "not PointerType or unexpected PointerType"); \
		if( ((struct Type ## PointerBody *)DATA_PTR( value ))->length < len ) \
			mrb_raise(mrb, E_ARGUMENT_ERROR, "size_is too short");		\
	}while(0)


#define GET_SET_BOOL( Type, TYPE )										\
	static mrb_value													\
	Type ## Pointer_aget(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
		mrb_int	subscript;												\
		TYPE	val;													\
																		\
		mrb_get_args(mrb, "i", &subscript );							\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (get)"); \
		val = pointerBody->buf[ subscript ];							\
		VALCHECK_MRB_ ## Type( mrb, val );								\
		return val ? mrb_true_value() : mrb_false_value();				\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_aset(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_int	subscript;												\
		mrb_value	val;													\
																		\
		mrb_get_args(mrb, "io", &subscript, &val );						\
																		\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (set)"); \
		pointerBody->buf[ subscript ] = mrb_test( val );				\
																		\
		return self;													\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_get_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
		TYPE	val;													\
																		\
		val = *pointerBody->buf;										\
		VALCHECK_MRB_ ## Type( mrb, val );								\
		return val ? mrb_true_value() : mrb_false_value();				\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_set_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_value	val;												\
																		\
		mrb_get_args(mrb, "o", &val );									\
																		\
		*pointerBody->buf = mrb_test( val );							\
		return self;													\
	}

#define GET_SET_CHAR( Type, TYPE )		GET_SET_INT( Type, TYPE )
#define GET_SET_INT( Type, TYPE )										\
	static mrb_value													\
	Type ## Pointer_aget(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
		mrb_int	subscript;												\
		TYPE	val;													\
																		\
		mrb_get_args(mrb, "i", &subscript );							\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (get)"); \
		val = pointerBody->buf[ subscript ];							\
		VALCHECK_MRB_ ## Type( mrb, val );								\
		return mrb_fixnum_value( val );									\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_aset(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_int	subscript;												\
		mrb_int	val;													\
																		\
		mrb_get_args(mrb, "ii", &subscript, &val );						\
																		\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (set)"); \
		VALCHECK_ ## Type ( mrb, val );									\
		pointerBody->buf[ subscript ] = val;							\
																		\
		return self;													\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_get_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
		TYPE	val;													\
																		\
		val = *pointerBody->buf;										\
		VALCHECK_MRB_ ## Type( mrb, val );								\
		return mrb_fixnum_value( val );									\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_set_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_int	val;													\
																		\
		mrb_get_args(mrb, "i", &val );									\
																		\
		VALCHECK_ ## Type ( mrb, val );									\
		*pointerBody->buf = val;										\
																		\
		return self;													\
	}

#define GET_SET_FLOAT( Type, TYPE )										\
	static mrb_value													\
	Type ## Pointer_aget(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
		mrb_int	subscript;												\
																		\
		mrb_get_args(mrb, "i", &subscript );							\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (get)"); \
		return mrb_float_value( pointerBody->buf[ subscript ] );		\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_aset(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_int	subscript;												\
		mrb_float	val;												\
																		\
		mrb_get_args(mrb, "if", &subscript, &val );						\
																		\
		if( subscript < 0 || subscript >= pointerBody->length )			\
			mrb_raise(mrb, E_INDEX_ERROR, "index is out of array (set)"); \
		pointerBody->buf[ subscript ] = val;							\
																		\
		return self;													\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_get_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
																		\
		return mrb_float_value( *pointerBody->buf );					\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_set_val(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self ); 	\
		mrb_float	val;												\
																		\
		mrb_get_args(mrb, "f", &val );									\
																		\
		*pointerBody->buf = val;										\
																		\
		return self;													\
	}

////  define Pointer classes ////
#define POINTER_CLASS( Type, TYPE )										\
																		\
	static void															\
	Type ## PointerBody_free( mrb_state *mrb, void *p )					\
	{																	\
		(void)mrb_free( mrb, p );										\
	}																	\
																		\
	struct mrb_data_type Type ## PointerBody_mrb_data_type =			\
		{																\
			"TECS::" #Type "Pointer",									\
			Type ## PointerBody_free									\
		};																\
																		\
	static mrb_value													\
	Type ## Pointer_initialize( mrb_state *mrb, mrb_value self)			\
	{																	\
		mrb_int	length;													\
		struct Type ## PointerBody *pointerBody;						\
																		\
		mrb_get_args(mrb, "i", &length );								\
		if( length < 0 )												\
			mrb_raise(mrb, E_INDEX_ERROR, "negative length");			\
		DATA_TYPE( self ) = &Type ## PointerBody_mrb_data_type;			\
		pointerBody = (struct Type ## PointerBody *)mrb_malloc(mrb, sizeof(struct Type ## PointerBody) + length * sizeof( TYPE ) ); \
		pointerBody->length = length;									\
		DATA_PTR( self ) = (void *)pointerBody;							\
						 												\
		return self;													\
	}																	\
																		\
	static mrb_value													\
	Type ## Pointer_size(mrb_state *mrb, mrb_value self)				\
	{																	\
		struct Type ## PointerBody *pointerBody = DATA_PTR( self );		\
																		\
		return mrb_fixnum_value( pointerBody->length );					\
	}																	\
																		\
	struct RClass *														\
	tecs_init_## Type ## Pointer(mrb_state *mrb, struct RClass *TECS)	\
	{																	\
		struct RClass *a;												\
																		\
		a = mrb_define_class_under(mrb, TECS, #Type "Pointer", mrb->object_class); \
		MRB_SET_INSTANCE_TT(a, MRB_TT_DATA);							\
																		\
		mrb_define_method(mrb, a, "initialize",      Type ## Pointer_initialize,   ARGS_REQ(1)); \
		mrb_define_method(mrb, a, "[]",              Type ## Pointer_aget,         ARGS_REQ(1)); \
		mrb_define_method(mrb, a, "value",           Type ## Pointer_get_val,      ARGS_NONE()); \
		mrb_define_method(mrb, a, "[]=",             Type ## Pointer_aset,         ARGS_REQ(2)); \
		mrb_define_method(mrb, a, "value=",          Type ## Pointer_set_val,      ARGS_REQ(1)); \
		mrb_define_method(mrb, a, "size",            Type ## Pointer_size,         ARGS_NONE()); \
		mrb_define_method(mrb, a, "length",          Type ## Pointer_size,         ARGS_NONE()); \
		return	a;														\
	}

static mrb_value
CharPointer_to_s( mrb_state *mrb, mrb_value self )
{
	struct CharPointerBody *pointerBody = DATA_PTR( self );
	return mrb_str_new( mrb, pointerBody->buf, strnlen( pointerBody->buf, pointerBody->length ) );
}

static mrb_value
CharPointer_from_s( mrb_state *mrb, mrb_value self )
{
	mrb_value str;
	struct CharPointerBody *pointerBody = DATA_PTR( self );

	mrb_get_args(mrb, "o", &str );
	if( mrb_type( str ) != MRB_TT_STRING ){
		mrb_raise(mrb, E_ARGUMENT_ERROR, "Not String");
	}

	strncpy( pointerBody->buf, RSTRING_PTR(str), pointerBody->length );
	return self;
}

/* Initialize TECSPointer classes */
void	init_TECSPointer( mrb_state *mrb, struct RClass *TECS );

#endif /* TECSPointer_h__ */

