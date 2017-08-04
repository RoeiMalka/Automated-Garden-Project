package models;

import io.ebean.Model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;
import java.util.Date;

@Entity
@Table(name="T_HUMIDITY")
public class Humidity extends Model {

    // Data Members
    @Column(name="PLANT_ID")
    private int plantId;

    @Column(name="RECORD_DATE")
    private Date recordDate;

    @Column(name="PLANT_HUMIDITY")
    private int plantHumidity;
}
