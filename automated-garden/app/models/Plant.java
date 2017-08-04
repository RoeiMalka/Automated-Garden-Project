package models;

import io.ebean.Model;
import javax.persistence.*;

@Entity
@Table(name="T_PLANTS")
public class Plant extends Model {

    // Data Members
    @Id
    @Column(name="PLANT_ID")
    private String plantId;

    @Column(name="PLANT_NAME")
    private String plantName;

    // Access Methods
    public String getPlantId() {
        return (this.plantId);
    }

    public String getPlantName() {
        return (this.plantName);
    }
}
