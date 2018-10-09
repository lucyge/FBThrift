/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.optionals;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@ThriftStruct("Vehicle")
public final class Vehicle
{
    @ThriftConstructor
    public Vehicle(
        @ThriftField(value=1, name="color", requiredness=Requiredness.NONE) final test.fixtures.optionals.Color color,
        @ThriftField(value=2, name="licensePlate", requiredness=Requiredness.OPTIONAL) final String licensePlate,
        @ThriftField(value=3, name="description", requiredness=Requiredness.OPTIONAL) final String description,
        @ThriftField(value=4, name="name", requiredness=Requiredness.OPTIONAL) final String name,
        @ThriftField(value=5, name="hasAC", requiredness=Requiredness.OPTIONAL) final Boolean hasAC
    ) {
        this.color = color;
        this.licensePlate = licensePlate;
        this.description = description;
        this.name = name;
        this.hasAC = hasAC;
    }

    public static class Builder {
        private test.fixtures.optionals.Color color;

        public Builder setColor(test.fixtures.optionals.Color color) {
            this.color = color;
            return this;
        }
        private String licensePlate;

        public Builder setLicensePlate(String licensePlate) {
            this.licensePlate = licensePlate;
            return this;
        }
        private String description;

        public Builder setDescription(String description) {
            this.description = description;
            return this;
        }
        private String name;

        public Builder setName(String name) {
            this.name = name;
            return this;
        }
        private Boolean hasAC;

        public Builder setHasAC(Boolean hasAC) {
            this.hasAC = hasAC;
            return this;
        }

        public Builder() { }
        public Builder(Vehicle other) {
            this.color = other.color;
            this.licensePlate = other.licensePlate;
            this.description = other.description;
            this.name = other.name;
            this.hasAC = other.hasAC;
        }

        public Vehicle build() {
            return new Vehicle (
                this.color,
                this.licensePlate,
                this.description,
                this.name,
                this.hasAC
            );
        }
    }

    private final test.fixtures.optionals.Color color;

    @ThriftField(value=1, name="color", requiredness=Requiredness.NONE)
    public test.fixtures.optionals.Color getColor() { return color; }

    private final String licensePlate;

    @ThriftField(value=2, name="licensePlate", requiredness=Requiredness.OPTIONAL)
    public String getLicensePlate() { return licensePlate; }

    private final String description;

    @ThriftField(value=3, name="description", requiredness=Requiredness.OPTIONAL)
    public String getDescription() { return description; }

    private final String name;

    @ThriftField(value=4, name="name", requiredness=Requiredness.OPTIONAL)
    public String getName() { return name; }

    private final Boolean hasAC;

    @ThriftField(value=5, name="hasAC", requiredness=Requiredness.OPTIONAL)
    public Boolean isHasAC() { return hasAC; }

    @Override
    public String toString()
    {
        return toStringHelper(this)
            .add("color", color)
            .add("licensePlate", licensePlate)
            .add("description", description)
            .add("name", name)
            .add("hasAC", hasAC)
            .toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        Vehicle other = (Vehicle)o;

        return
            Objects.equals(color, other.color) &&
            Objects.equals(licensePlate, other.licensePlate) &&
            Objects.equals(description, other.description) &&
            Objects.equals(name, other.name) &&
            Objects.equals(hasAC, other.hasAC);
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            color,
            licensePlate,
            description,
            name,
            hasAC
        });
    }
}
