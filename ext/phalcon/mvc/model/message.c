
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Model\Message as Message;
 *
 *  class Robots extends Phalcon\Mvc\Model
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if (this->name == 'Peter') {
 *        text = "A robot cannot be named Peter";
 *        field = "name";
 *        type = "InvalidValue";
 *        message = new Message(text, field, type);
 *        this->appendMessage(message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Message, phalcon, mvc_model_message, phalcon_mvc_model_message_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_message_ce TSRMLS_CC, 1, phalcon_mvc_model_messageinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string message
 * @param string field
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __construct) {

	zval *message_param = NULL, *field = NULL, *type = NULL, *model = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &message_param, &field, &type, &model);

		zephir_get_strval(message, message_param);
	if (!field) {
		ZEPHIR_CPY_WRT(field, ZEPHIR_GLOBAL(global_null));
	}
	if (!type) {
		ZEPHIR_CPY_WRT(type, ZEPHIR_GLOBAL(global_null));
	}
	if (!model) {
		ZEPHIR_CPY_WRT(model, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	if ((Z_TYPE_P(model) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets message type
 *
 * @param string type
 * @return Phalcon\Mvc\Model\MessageInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setType) {

	zval *type;

	zephir_fetch_params(0, 1, 0, &type);



	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns message type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Sets verbose message
 *
 * @param string message
 * @return Phalcon\Mvc\Model\MessageInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage) {

	zval *message_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Sets field name related to message
 *
 * @param string field
 * @return Phalcon\Mvc\Model\MessageInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setField) {

	zval *field_param = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

		zephir_get_strval(field, field_param);


	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns field name related to message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getField) {


	RETURN_MEMBER(this_ptr, "_field");

}

/**
 * Set the model who generates the message
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setModel) {

	zval *model;

	zephir_fetch_params(0, 1, 0, &model);



	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the model that produced the message
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getModel) {


	RETURN_MEMBER(this_ptr, "_model");

}

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Magic __set_state helps to re-build messages variable exporting
 *
 * @param array $message
 * @return Phalcon\Mvc\Model\MessageInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state) {

	zval *message, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	object_init_ex(return_value, phalcon_mvc_model_message_ce);
	zephir_array_fetch_string(&_0, message, SL("_message"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_1, message, SL("_field"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_2, message, SL("_type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_method_p3_noret(return_value, "__construct", _0, _1, _2);
	RETURN_MM();

}

