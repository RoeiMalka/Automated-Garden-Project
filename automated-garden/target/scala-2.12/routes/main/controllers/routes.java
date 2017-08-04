
// @GENERATOR:play-routes-compiler
// @SOURCE:/Users/roeimalka/Desktop/Project/automated-garden/conf/routes
// @DATE:Sun Jul 30 23:52:38 IDT 2017

package controllers;

import router.RoutesPrefix;

public class routes {
  
  public static final controllers.ReverseAssets Assets = new controllers.ReverseAssets(RoutesPrefix.byNamePrefix());

  public static class javascript {
    
    public static final controllers.javascript.ReverseAssets Assets = new controllers.javascript.ReverseAssets(RoutesPrefix.byNamePrefix());
  }

}
