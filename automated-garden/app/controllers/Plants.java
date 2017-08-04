package controllers;

import com.fasterxml.jackson.databind.JsonNode;
import play.mvc.Controller;
import play.mvc.Result;


public class Plants extends Controller {

    public static Result addHydration() {
        JsonNode data = request().body().asJson();

        return ok();
    }
}
