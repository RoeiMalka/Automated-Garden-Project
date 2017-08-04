package controllers;

import com.fasterxml.jackson.databind.JsonNode;
import models.Plant;
import play.libs.Json;
import play.mvc.Controller;
import play.mvc.Result;


public class Plants extends Controller {

    public static Result addHydration() {
        JsonNode data = request().body().asJson();

        Plant plant = Json.fromJson(data, Plant.class);
        return ok();
    }
}
