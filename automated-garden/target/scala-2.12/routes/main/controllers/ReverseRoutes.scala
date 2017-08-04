
// @GENERATOR:play-routes-compiler
// @SOURCE:/Users/roeimalka/Desktop/Project/automated-garden/conf/routes
// @DATE:Sun Jul 30 23:52:38 IDT 2017

import play.api.mvc.Call


import _root_.controllers.Assets.Asset
import _root_.play.libs.F

// @LINE:6
package controllers {

  // @LINE:6
  class ReverseAssets(_prefix: => String) {
    def _defaultPrefix: String = {
      if (_prefix.endsWith("/")) "" else "/"
    }

  
    // @LINE:6
    def at(): Call = {
      implicit val _rrc = new play.core.routing.ReverseRouteContext(Map(("path", "/public/views"), ("file", "index.html")))
      Call("GET", _prefix)
    }
  
  }


}
