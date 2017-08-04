
// @GENERATOR:play-routes-compiler
// @SOURCE:/Users/roeimalka/Desktop/Project/automated-garden/conf/routes
// @DATE:Sun Jul 30 23:52:38 IDT 2017


package router {
  object RoutesPrefix {
    private var _prefix: String = "/"
    def setPrefix(p: String): Unit = {
      _prefix = p
    }
    def prefix: String = _prefix
    val byNamePrefix: Function0[String] = { () => prefix }
  }
}
