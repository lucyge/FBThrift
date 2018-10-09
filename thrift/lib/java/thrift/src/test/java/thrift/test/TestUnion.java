/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package thrift.test;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.facebook.thrift.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial", "unchecked" })
public class TestUnion extends TUnion<TestUnion> implements Comparable<TestUnion> {
  public static boolean DEFAULT_PRETTY_PRINT = true;
  private static final TStruct STRUCT_DESC = new TStruct("TestUnion");
  private static final TField STRING_FIELD_FIELD_DESC = new TField("string_field", TType.STRING, (short)1);
  private static final TField I32_FIELD_FIELD_DESC = new TField("i32_field", TType.I32, (short)2);
  private static final TField STRUCT_FIELD_FIELD_DESC = new TField("struct_field", TType.STRUCT, (short)3);
  private static final TField STRUCT_LIST_FIELD_DESC = new TField("struct_list", TType.LIST, (short)4);
  private static final TField OTHER_I32_FIELD_FIELD_DESC = new TField("other_i32_field", TType.I32, (short)5);

  public static final int STRING_FIELD = 1;
  public static final int I32_FIELD = 2;
  public static final int STRUCT_FIELD = 3;
  public static final int STRUCT_LIST = 4;
  public static final int OTHER_I32_FIELD = 5;

  public static final Map<Integer, FieldMetaData> metaDataMap;
  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(STRING_FIELD, new FieldMetaData("string_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(I32_FIELD, new FieldMetaData("i32_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    tmpMetaDataMap.put(STRUCT_FIELD, new FieldMetaData("struct_field", TFieldRequirementType.DEFAULT, 
        new StructMetaData(TType.STRUCT, OneOfEach.class)));
    tmpMetaDataMap.put(STRUCT_LIST, new FieldMetaData("struct_list", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new StructMetaData(TType.STRUCT, RandomStuff.class))));
    tmpMetaDataMap.put(OTHER_I32_FIELD, new FieldMetaData("other_i32_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  public TestUnion() {
    super();
  }

  public TestUnion(int setField, Object value) {
    super(setField, value);
  }

  public TestUnion(TestUnion other) {
    super(other);
  }
  public TestUnion deepCopy() {
    return new TestUnion(this);
  }

  public static TestUnion string_field(String value) {
    TestUnion x = new TestUnion();
    x.setString_field(value);
    return x;
  }

  public static TestUnion i32_field(int value) {
    TestUnion x = new TestUnion();
    x.setI32_field(value);
    return x;
  }

  public static TestUnion struct_field(OneOfEach value) {
    TestUnion x = new TestUnion();
    x.setStruct_field(value);
    return x;
  }

  public static TestUnion struct_list(List<RandomStuff> value) {
    TestUnion x = new TestUnion();
    x.setStruct_list(value);
    return x;
  }

  public static TestUnion other_i32_field(int value) {
    TestUnion x = new TestUnion();
    x.setOther_i32_field(value);
    return x;
  }


  @Override
  protected void checkType(short setField, Object value) throws ClassCastException {
    switch (setField) {
      case STRING_FIELD:
        if (value instanceof String) {
          break;
        }
        throw new ClassCastException("Was expecting value of type String for field 'string_field', but got " + value.getClass().getSimpleName());
      case I32_FIELD:
        if (value instanceof Integer) {
          break;
        }
        throw new ClassCastException("Was expecting value of type Integer for field 'i32_field', but got " + value.getClass().getSimpleName());
      case STRUCT_FIELD:
        if (value instanceof OneOfEach) {
          break;
        }
        throw new ClassCastException("Was expecting value of type OneOfEach for field 'struct_field', but got " + value.getClass().getSimpleName());
      case STRUCT_LIST:
        if (value instanceof List) {
          break;
        }
        throw new ClassCastException("Was expecting value of type List<RandomStuff> for field 'struct_list', but got " + value.getClass().getSimpleName());
      case OTHER_I32_FIELD:
        if (value instanceof Integer) {
          break;
        }
        throw new ClassCastException("Was expecting value of type Integer for field 'other_i32_field', but got " + value.getClass().getSimpleName());
      default:
        throw new IllegalArgumentException("Unknown field id " + setField);
    }
  }

  @Override
  public void read(TProtocol iprot) throws TException {
    setField_ = 0;
    value_ = null;
    iprot.readStructBegin(metaDataMap);
    TField field = iprot.readFieldBegin();
    if (field.type != TType.STOP)
    {
      value_ = readValue(iprot, field);
      if (value_ != null)
      {
        switch (field.id) {
          case STRING_FIELD:
            if (field.type == STRING_FIELD_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case I32_FIELD:
            if (field.type == I32_FIELD_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case STRUCT_FIELD:
            if (field.type == STRUCT_FIELD_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case STRUCT_LIST:
            if (field.type == STRUCT_LIST_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case OTHER_I32_FIELD:
            if (field.type == OTHER_I32_FIELD_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
        }
      }
      iprot.readFieldEnd();
      iprot.readFieldBegin();
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();
  }

  @Override
  protected Object readValue(TProtocol iprot, TField field) throws TException {
    switch (field.id) {
      case STRING_FIELD:
        if (field.type == STRING_FIELD_FIELD_DESC.type) {
          String string_field;
          string_field = iprot.readString();
          return string_field;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case I32_FIELD:
        if (field.type == I32_FIELD_FIELD_DESC.type) {
          Integer i32_field;
          i32_field = iprot.readI32();
          return i32_field;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case STRUCT_FIELD:
        if (field.type == STRUCT_FIELD_FIELD_DESC.type) {
          OneOfEach struct_field;
          struct_field = new OneOfEach();
          struct_field.read(iprot);
          return struct_field;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case STRUCT_LIST:
        if (field.type == STRUCT_LIST_FIELD_DESC.type) {
          List<RandomStuff> struct_list;
          {
            TList _list537 = iprot.readListBegin();
            struct_list = new ArrayList<RandomStuff>(Math.max(0, _list537.size));
            for (int _i538 = 0; 
                 (_list537.size < 0) ? iprot.peekList() : (_i538 < _list537.size); 
                 ++_i538)
            {
              RandomStuff _elem539;
              _elem539 = new RandomStuff();
              _elem539.read(iprot);
              struct_list.add(_elem539);
            }
            iprot.readListEnd();
          }
          return struct_list;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case OTHER_I32_FIELD:
        if (field.type == OTHER_I32_FIELD_FIELD_DESC.type) {
          Integer other_i32_field;
          other_i32_field = iprot.readI32();
          return other_i32_field;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      default:
        TProtocolUtil.skip(iprot, field.type);
        return null;
    }
  }

  @Override
  protected void writeValue(TProtocol oprot, short setField, Object value) throws TException {
    switch (setField) {
      case STRING_FIELD:
        String string_field = (String)getFieldValue();
        oprot.writeString(string_field);
        return;
      case I32_FIELD:
        Integer i32_field = (Integer)getFieldValue();
        oprot.writeI32(i32_field);
        return;
      case STRUCT_FIELD:
        OneOfEach struct_field = (OneOfEach)getFieldValue();
        struct_field.write(oprot);
        return;
      case STRUCT_LIST:
        List<RandomStuff> struct_list = (List<RandomStuff>)getFieldValue();
        {
          oprot.writeListBegin(new TList(TType.STRUCT, struct_list.size()));
          for (RandomStuff _iter540 : struct_list)          {
            _iter540.write(oprot);
          }
          oprot.writeListEnd();
        }
        return;
      case OTHER_I32_FIELD:
        Integer other_i32_field = (Integer)getFieldValue();
        oprot.writeI32(other_i32_field);
        return;
      default:
        throw new IllegalStateException("Cannot write union with unknown field " + setField);
    }
  }

  @Override
  protected TField getFieldDesc(int setField) {
    switch (setField) {
      case STRING_FIELD:
        return STRING_FIELD_FIELD_DESC;
      case I32_FIELD:
        return I32_FIELD_FIELD_DESC;
      case STRUCT_FIELD:
        return STRUCT_FIELD_FIELD_DESC;
      case STRUCT_LIST:
        return STRUCT_LIST_FIELD_DESC;
      case OTHER_I32_FIELD:
        return OTHER_I32_FIELD_FIELD_DESC;
      default:
        throw new IllegalArgumentException("Unknown field id " + setField);
    }
  }

  @Override
  protected TStruct getStructDesc() {
    return STRUCT_DESC;
  }

  /**
   * A doc string
   */
  public String  getString_field() {
    if (getSetField() == STRING_FIELD) {
      return (String)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'string_field' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  /**
   * A doc string
   */
  public void setString_field(String value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRING_FIELD;
    value_ = value;
  }

  public int  getI32_field() {
    if (getSetField() == I32_FIELD) {
      return (Integer)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'i32_field' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setI32_field(int value) {
    setField_ = I32_FIELD;
    value_ = value;
  }

  public OneOfEach  getStruct_field() {
    if (getSetField() == STRUCT_FIELD) {
      return (OneOfEach)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'struct_field' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setStruct_field(OneOfEach value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRUCT_FIELD;
    value_ = value;
  }

  public List<RandomStuff>  getStruct_list() {
    if (getSetField() == STRUCT_LIST) {
      return (List<RandomStuff>)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'struct_list' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setStruct_list(List<RandomStuff> value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRUCT_LIST;
    value_ = value;
  }

  public int  getOther_i32_field() {
    if (getSetField() == OTHER_I32_FIELD) {
      return (Integer)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'other_i32_field' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setOther_i32_field(int value) {
    setField_ = OTHER_I32_FIELD;
    value_ = value;
  }

  public boolean equals(Object other) {
    if (other instanceof TestUnion) {
      return equals((TestUnion)other);
    } else {
      return false;
    }
  }

  public boolean equals(TestUnion other) {
    return equalsNobinaryImpl(other);
  }

  @Override
  public int compareTo(TestUnion other) {
    return compareToImpl(other);
  }


  /**
   * If you'd like this to perform more respectably, use the hashcode generator option.
   */
  @Override
  public int hashCode() {
    return 0;
  }

  @Override
  public String toString() {
    return toString(DEFAULT_PRETTY_PRINT);
  }

  @Override
  public String toString(boolean prettyPrint) {
    return toString(1, prettyPrint);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("TestUnion");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    // Only print this field if it is the set field
    if (getSetField() == STRING_FIELD)
    {
      sb.append(indentStr);
      sb.append("string_field");
      sb.append(space);
      sb.append(":").append(space);
      if (this. getString_field() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this. getString_field(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == I32_FIELD)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("i32_field");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this. getI32_field(), indent + 1, prettyPrint));
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == STRUCT_FIELD)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("struct_field");
      sb.append(space);
      sb.append(":").append(space);
      if (this. getStruct_field() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this. getStruct_field(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == STRUCT_LIST)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("struct_list");
      sb.append(space);
      sb.append(":").append(space);
      if (this. getStruct_list() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this. getStruct_list(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == OTHER_I32_FIELD)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("other_i32_field");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this. getOther_i32_field(), indent + 1, prettyPrint));
      first = false;
    }
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }


}
