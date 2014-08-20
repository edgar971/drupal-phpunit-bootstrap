PHPUNIT DRUPAL 7 BOOTSTRAP SCRIPT
-------------------------------

Use phpunit with drupal 7. This script works with multisite installation and contains and phpunit.xml.dist example to organize your testsuites.

USAGE EXAMPLE :
----------------

* Put "phpunit.xml.dist" and "phpunit.drupal_bootstrap.php" at the root your Drupal installation
* In phpunit.xml.dist, configure testSuite attribute to match your tests files paths.
* In phpunit.drupal_bootstrap.php, edit $drupal_root and $http_host if needed.
* run phpunit command from the root of your drupal installation


