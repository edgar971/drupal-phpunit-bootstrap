<?php
/**
 * Class to bootstrap Drupal, to write PHPUnit tests
 * This bootstrap is functionnal with multisites installation.
 */

$drupal = new drupalBootstrap();
$drupal->bootstrap();

class drupalBootstrap {

  // this script location.
  protected $scriptDirectory = '';
  protected $root = '';

  function getRoot() {
    return $this->root;
  }

  function __construct($root = '') {
    $this->simulateServerVariables();
    $this->root = $root; 
    if (!$root) {
      $this->scriptDirectory = getcwd();
      $this->root = $this->locateDrupalRootFromPath($this->scriptDirectory);
    }
    set_include_path($this->root . PATH_SEPARATOR . get_include_path());
  }

  function simulateServerVariables() {
    $_SERVER['REMOTE_ADDR'] = '127.0.0.1';
    $_SERVER['HTTP_HOST'] = 'design.drupal7.rockgrey.okcdev.fr';
    $_SERVER['SCRIPT_NAME'] = '/index.php';
  }

  /**
   * Try to guess drupal Root, recursively going up in directory tree from current directory.
   */
  private function locateDrupalRootFromPath($path) {
    while ($path != '/') {
      if (file_exists($path . '/index.php') && file_exists($path . '/includes/bootstrap.inc')) {
        $root = $path;
        break;
      }
      $path = dirname($path);
    }
    return $root;
  }

  function bootstrap() {
    define('DRUPAL_ROOT', $this->getRoot());
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  }


}

