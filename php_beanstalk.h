/*
  +----------------------------------------------------------------------+
  | PHP Version 5  and Version 7                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_BEANSTALK_H
#define PHP_BEANSTALK_H

extern zend_module_entry beanstalk_module_entry;
#define phpext_beanstalk_ptr &beans3alk_module_entry

#define PHP_BEANSTALK_VERSION "0.1.3" /* Replace with version number for your extension */
#define SUPPORTED_PHP_VERSION "php5 and php7"

#ifdef PHP_WIN32
#	define PHP_BEANSTALK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_BEANSTALK_API __attribute__ ((visibility("default")))
#else
#	define PHP_BEANSTALK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include "php_streams.h"

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(beanstalk)
	//php_stream* gstream;
ZEND_END_MODULE_GLOBALS(beanstalk)
*/
/* In every utility function you add that needs to use variables 
   in php_beanstalk_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as BEANSTALK_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

PHP_MINIT_FUNCTION(beanstalk);
PHP_MSHUTDOWN_FUNCTION(beanstalk);
PHP_RINIT_FUNCTION(beanstalk);
PHP_RSHUTDOWN_FUNCTION(beanstalk);
PHP_MINFO_FUNCTION(beanstalk);
//PHP_METHOD(Beanstalk,__construct);
PHP_FUNCTION(beanstalk_connect);
PHP_FUNCTION(beanstalk_close);
PHP_FUNCTION(beanstalk_put);
PHP_FUNCTION(beanstalk_close);
PHP_FUNCTION(beanstalk_peekReady);
PHP_FUNCTION(beanstalk_peek);
PHP_FUNCTION(beanstalk_delete);
PHP_FUNCTION(beanstalk_stats);
PHP_FUNCTION(beanstalk_bury);
PHP_FUNCTION(beanstalk_ignore);
PHP_FUNCTION(beanstalk_kick);
PHP_FUNCTION(beanstalk_kickJob);
PHP_FUNCTION(beanstalk_listTubes);
PHP_FUNCTION(beanstalk_listTubesWatched);
PHP_FUNCTION(beanstalk_listTubeUsed);
PHP_FUNCTION(beanstalk_pauseTube);
PHP_FUNCTION(beanstalk_resumeTube);
PHP_FUNCTION(beanstalk_peekDelayed);
PHP_FUNCTION(beanstalk_peekBuried);
PHP_FUNCTION(beanstalk_putInTube);
PHP_FUNCTION(beanstalk_release);
PHP_FUNCTION(beanstalk_reserve);
//PHP_FUNCTION(beanstalk_reserveFromTube);
PHP_FUNCTION(beanstalk_statsJob);
PHP_FUNCTION(beanstalk_statsTube);
PHP_FUNCTION(beanstalk_touch);
PHP_FUNCTION(beanstalk_useTube);
PHP_FUNCTION(beanstalk_watch);


#ifdef ZTS
#define BEANSTALK_G(v) TSRMG(beanstalk_globals_id, zend_beanstalk_globals *, v)
#else
#define BEANSTALK_G(v) (beanstalk_globals.v)
#endif

/**
 * beanstalk string
 */
typedef struct
{
	char* pStr;
	int iLen;
}BSString;

/**
 * beanstalk key-value pair
 */
typedef struct
{
	BSString key;
	BSString value;
} BSKeyVal;

#endif	/* PHP_BEANSTALK_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
