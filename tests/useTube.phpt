--TEST--
Check for useTube
--SKIPIF--
<?php if (!extension_loaded("beanstalk")) print "skip"; ?>
--FILE--
<?php 
$arrConfig = include __DIR__ . '/../include/config.inc';

$b = beanstalk_connect( $arrConfig['host'], $arrConfig['port'] );

$jobID = beanstalk_putInTube( $b, 'test-tube-a', 'test' );
var_dump( beanstalk_useTube( $b, 'test-tube-a' ));

$b->putInTube( 'test-tube-a', 'test' );
var_dump( $b->useTube( 'test-tube-a' ));

beanstalk_delete( $b, $jobID );
beanstalk_close( $b );

/*
	you can add regression tests for your extension here

  the output of your test code has to be equal to the
  text in the --EXPECT-- section below for the tests
  to pass, differences between the output and the
  expected text are interpreted as failure

	see php5/README.TESTING for further information on
  writing regression tests 				
done
*/
?>
--EXPECTF--
string(%d) "test-tube-a"
string(%d) "test-tube-a"