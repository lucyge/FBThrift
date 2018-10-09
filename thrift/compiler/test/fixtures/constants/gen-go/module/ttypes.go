// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = bytes.Equal

var GoUnusedProtection__ int;

type EmptyEnum int64
const (
)

var EmptyEnumToName = map[EmptyEnum]string {
}

var EmptyEnumToValue = map[string]EmptyEnum {
}

func (p EmptyEnum) String() string {
  if v, ok := EmptyEnumToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func EmptyEnumFromString(s string) (EmptyEnum, error) {
  if v, ok := EmptyEnumToValue[s]; ok {
    return v, nil
  }
  return EmptyEnum(0), fmt.Errorf("not a valid EmptyEnum string")
}

func EmptyEnumPtr(v EmptyEnum) *EmptyEnum { return &v }

type City int64
const (
  City_NYC City = 0
  City_MPK City = 1
  City_SEA City = 2
  City_LON City = 3
)

var CityToName = map[City]string {
  City_NYC: "NYC",
  City_MPK: "MPK",
  City_SEA: "SEA",
  City_LON: "LON",
}

var CityToValue = map[string]City {
  "NYC": City_NYC,
  "MPK": City_MPK,
  "SEA": City_SEA,
  "LON": City_LON,
}

func (p City) String() string {
  if v, ok := CityToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func CityFromString(s string) (City, error) {
  if v, ok := CityToValue[s]; ok {
    return v, nil
  }
  return City(0), fmt.Errorf("not a valid City string")
}

func CityPtr(v City) *City { return &v }

type Company int64
const (
  Company_FACEBOOK Company = 0
  Company_WHATSAPP Company = 1
  Company_OCULUS Company = 2
  Company_INSTAGRAM Company = 3
)

var CompanyToName = map[Company]string {
  Company_FACEBOOK: "FACEBOOK",
  Company_WHATSAPP: "WHATSAPP",
  Company_OCULUS: "OCULUS",
  Company_INSTAGRAM: "INSTAGRAM",
}

var CompanyToValue = map[string]Company {
  "FACEBOOK": Company_FACEBOOK,
  "WHATSAPP": Company_WHATSAPP,
  "OCULUS": Company_OCULUS,
  "INSTAGRAM": Company_INSTAGRAM,
}

func (p Company) String() string {
  if v, ok := CompanyToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func CompanyFromString(s string) (Company, error) {
  if v, ok := CompanyToValue[s]; ok {
    return v, nil
  }
  return Company(0), fmt.Errorf("not a valid Company string")
}

func CompanyPtr(v Company) *Company { return &v }

// Attributes:
//  - Weeks
//  - Title
//  - Employer
type Internship struct {
  Weeks int32 `thrift:"weeks,1,required" db:"weeks" json:"weeks"`
  Title string `thrift:"title,2" db:"title" json:"title"`
  Employer *Company `thrift:"employer,3" db:"employer" json:"employer,omitempty"`
}

func NewInternship() *Internship {
  return &Internship{}
}


func (p *Internship) GetWeeks() int32 {
  return p.Weeks
}

func (p *Internship) GetTitle() string {
  return p.Title
}
var Internship_Employer_DEFAULT Company
func (p *Internship) GetEmployer() Company {
  if !p.IsSetEmployer() {
    return Internship_Employer_DEFAULT
  }
return *p.Employer
}
func (p *Internship) IsSetEmployer() bool {
  return p.Employer != nil
}

func (p *Internship) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }

  var issetWeeks bool = false;

  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
      issetWeeks = true
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  if !issetWeeks{
    return thrift.NewTProtocolExceptionWithType(thrift.INVALID_DATA, fmt.Errorf("Required field Weeks is not set"));
  }
  return nil
}

func (p *Internship)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.Weeks = v
}
  return nil
}

func (p *Internship)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.Title = v
}
  return nil
}

func (p *Internship)  ReadField3(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 3: ", err)
} else {
  temp := Company(v)
  p.Employer = &temp
}
  return nil
}

func (p *Internship) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("Internship"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Internship) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("weeks", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:weeks: ", p), err) }
  if err := oprot.WriteI32(int32(p.Weeks)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.weeks (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:weeks: ", p), err) }
  return err
}

func (p *Internship) writeField2(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("title", thrift.STRING, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:title: ", p), err) }
  if err := oprot.WriteString(string(p.Title)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.title (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:title: ", p), err) }
  return err
}

func (p *Internship) writeField3(oprot thrift.TProtocol) (err error) {
  if p.IsSetEmployer() {
    if err := oprot.WriteFieldBegin("employer", thrift.I32, 3); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:employer: ", p), err) }
    if err := oprot.WriteI32(int32(*p.Employer)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.employer (3) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 3:employer: ", p), err) }
  }
  return err
}

func (p *Internship) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Internship(%+v)", *p)
}

// Attributes:
//  - City
type UnEnumStruct struct {
  City City `thrift:"city,1" db:"city" json:"city"`
}

func NewUnEnumStruct() *UnEnumStruct {
  return &UnEnumStruct{
City: -1,
}
}


func (p *UnEnumStruct) GetCity() City {
  return p.City
}
func (p *UnEnumStruct) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *UnEnumStruct)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  temp := City(v)
  p.City = temp
}
  return nil
}

func (p *UnEnumStruct) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("UnEnumStruct"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *UnEnumStruct) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("city", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:city: ", p), err) }
  if err := oprot.WriteI32(int32(p.City)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.city (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:city: ", p), err) }
  return err
}

func (p *UnEnumStruct) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("UnEnumStruct(%+v)", *p)
}

// Attributes:
//  - Min
//  - Max
type Range struct {
  Min int32 `thrift:"min,1,required" db:"min" json:"min"`
  Max int32 `thrift:"max,2,required" db:"max" json:"max"`
}

func NewRange() *Range {
  return &Range{}
}


func (p *Range) GetMin() int32 {
  return p.Min
}

func (p *Range) GetMax() int32 {
  return p.Max
}
func (p *Range) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }

  var issetMin bool = false;
  var issetMax bool = false;

  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
      issetMin = true
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
      issetMax = true
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  if !issetMin{
    return thrift.NewTProtocolExceptionWithType(thrift.INVALID_DATA, fmt.Errorf("Required field Min is not set"));
  }
  if !issetMax{
    return thrift.NewTProtocolExceptionWithType(thrift.INVALID_DATA, fmt.Errorf("Required field Max is not set"));
  }
  return nil
}

func (p *Range)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.Min = v
}
  return nil
}

func (p *Range)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.Max = v
}
  return nil
}

func (p *Range) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("Range"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Range) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("min", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:min: ", p), err) }
  if err := oprot.WriteI32(int32(p.Min)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.min (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:min: ", p), err) }
  return err
}

func (p *Range) writeField2(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("max", thrift.I32, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:max: ", p), err) }
  if err := oprot.WriteI32(int32(p.Max)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.max (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:max: ", p), err) }
  return err
}

func (p *Range) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Range(%+v)", *p)
}

// Attributes:
//  - A
//  - B
type Struct1 struct {
  A int32 `thrift:"a,1" db:"a" json:"a"`
  B string `thrift:"b,2" db:"b" json:"b"`
}

func NewStruct1() *Struct1 {
  return &Struct1{
A: 1234567,

B: "<uninitialized>",
}
}


func (p *Struct1) GetA() int32 {
  return p.A
}

func (p *Struct1) GetB() string {
  return p.B
}
func (p *Struct1) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Struct1)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.A = v
}
  return nil
}

func (p *Struct1)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.B = v
}
  return nil
}

func (p *Struct1) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("struct1"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Struct1) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("a", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:a: ", p), err) }
  if err := oprot.WriteI32(int32(p.A)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.a (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:a: ", p), err) }
  return err
}

func (p *Struct1) writeField2(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("b", thrift.STRING, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:b: ", p), err) }
  if err := oprot.WriteString(string(p.B)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.b (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:b: ", p), err) }
  return err
}

func (p *Struct1) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Struct1(%+v)", *p)
}

// Attributes:
//  - A
//  - B
//  - C
//  - D
type Struct2 struct {
  A int32 `thrift:"a,1" db:"a" json:"a"`
  B string `thrift:"b,2" db:"b" json:"b"`
  C *Struct1 `thrift:"c,3" db:"c" json:"c"`
  D []int32 `thrift:"d,4" db:"d" json:"d"`
}

func NewStruct2() *Struct2 {
  return &Struct2{}
}


func (p *Struct2) GetA() int32 {
  return p.A
}

func (p *Struct2) GetB() string {
  return p.B
}
var Struct2_C_DEFAULT *Struct1
func (p *Struct2) GetC() *Struct1 {
  if !p.IsSetC() {
    return Struct2_C_DEFAULT
  }
return p.C
}

func (p *Struct2) GetD() []int32 {
  return p.D
}
func (p *Struct2) IsSetC() bool {
  return p.C != nil
}

func (p *Struct2) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Struct2)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.A = v
}
  return nil
}

func (p *Struct2)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.B = v
}
  return nil
}

func (p *Struct2)  ReadField3(iprot thrift.TProtocol) error {
  p.C = NewStruct1()
  if err := p.C.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.C), err)
  }
  return nil
}

func (p *Struct2)  ReadField4(iprot thrift.TProtocol) error {
  _, size, err := iprot.ReadListBegin()
  if err != nil {
    return thrift.PrependError("error reading list begin: ", err)
  }
  tSlice := make([]int32, 0, size)
  p.D =  tSlice
  for i := 0; i < size; i ++ {
var _elem0 int32
    if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 0: ", err)
} else {
    _elem0 = v
}
    p.D = append(p.D, _elem0)
  }
  if err := iprot.ReadListEnd(); err != nil {
    return thrift.PrependError("error reading list end: ", err)
  }
  return nil
}

func (p *Struct2) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("struct2"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Struct2) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("a", thrift.I32, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:a: ", p), err) }
  if err := oprot.WriteI32(int32(p.A)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.a (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:a: ", p), err) }
  return err
}

func (p *Struct2) writeField2(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("b", thrift.STRING, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:b: ", p), err) }
  if err := oprot.WriteString(string(p.B)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.b (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:b: ", p), err) }
  return err
}

func (p *Struct2) writeField3(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("c", thrift.STRUCT, 3); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:c: ", p), err) }
  if err := p.C.Write(oprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.C), err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 3:c: ", p), err) }
  return err
}

func (p *Struct2) writeField4(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("d", thrift.LIST, 4); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:d: ", p), err) }
  if err := oprot.WriteListBegin(thrift.I32, len(p.D)); err != nil {
    return thrift.PrependError("error writing list begin: ", err)
  }
  for _, v := range p.D {
    if err := oprot.WriteI32(int32(v)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
  }
  if err := oprot.WriteListEnd(); err != nil {
    return thrift.PrependError("error writing list end: ", err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 4:d: ", p), err) }
  return err
}

func (p *Struct2) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Struct2(%+v)", *p)
}

// Attributes:
//  - A
//  - B
//  - C
type Struct3 struct {
  A string `thrift:"a,1" db:"a" json:"a"`
  B int32 `thrift:"b,2" db:"b" json:"b"`
  C *Struct2 `thrift:"c,3" db:"c" json:"c"`
}

func NewStruct3() *Struct3 {
  return &Struct3{}
}


func (p *Struct3) GetA() string {
  return p.A
}

func (p *Struct3) GetB() int32 {
  return p.B
}
var Struct3_C_DEFAULT *Struct2
func (p *Struct3) GetC() *Struct2 {
  if !p.IsSetC() {
    return Struct3_C_DEFAULT
  }
return p.C
}
func (p *Struct3) IsSetC() bool {
  return p.C != nil
}

func (p *Struct3) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Struct3)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.A = v
}
  return nil
}

func (p *Struct3)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.B = v
}
  return nil
}

func (p *Struct3)  ReadField3(iprot thrift.TProtocol) error {
  p.C = NewStruct2()
  if err := p.C.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.C), err)
  }
  return nil
}

func (p *Struct3) Write(oprot thrift.TProtocol) error {
  if err := oprot.WriteStructBegin("struct3"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Struct3) writeField1(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("a", thrift.STRING, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:a: ", p), err) }
  if err := oprot.WriteString(string(p.A)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.a (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:a: ", p), err) }
  return err
}

func (p *Struct3) writeField2(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("b", thrift.I32, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:b: ", p), err) }
  if err := oprot.WriteI32(int32(p.B)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.b (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:b: ", p), err) }
  return err
}

func (p *Struct3) writeField3(oprot thrift.TProtocol) (err error) {
  if err := oprot.WriteFieldBegin("c", thrift.STRUCT, 3); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:c: ", p), err) }
  if err := p.C.Write(oprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.C), err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 3:c: ", p), err) }
  return err
}

func (p *Struct3) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Struct3(%+v)", *p)
}

// Attributes:
//  - I
//  - D
type Union1 struct {
  I *int32 `thrift:"i,1" db:"i" json:"i,omitempty"`
  D *float64 `thrift:"d,2" db:"d" json:"d,omitempty"`
}

func NewUnion1() *Union1 {
  return &Union1{}
}

var Union1_I_DEFAULT int32
func (p *Union1) GetI() int32 {
  if !p.IsSetI() {
    return Union1_I_DEFAULT
  }
return *p.I
}
var Union1_D_DEFAULT float64
func (p *Union1) GetD() float64 {
  if !p.IsSetD() {
    return Union1_D_DEFAULT
  }
return *p.D
}
func (p *Union1) CountSetFieldsUnion1() int {
  count := 0
  if (p.IsSetI()) {
    count++
  }
  if (p.IsSetD()) {
    count++
  }
  return count

}

func (p *Union1) IsSetI() bool {
  return p.I != nil
}

func (p *Union1) IsSetD() bool {
  return p.D != nil
}

func (p *Union1) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Union1)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.I = &v
}
  return nil
}

func (p *Union1)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.D = &v
}
  return nil
}

func (p *Union1) Write(oprot thrift.TProtocol) error {
  if c := p.CountSetFieldsUnion1(); c != 1 {
    return fmt.Errorf("%T write union: exactly one field must be set (%d set).", p, c)
  }
  if err := oprot.WriteStructBegin("union1"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Union1) writeField1(oprot thrift.TProtocol) (err error) {
  if p.IsSetI() {
    if err := oprot.WriteFieldBegin("i", thrift.I32, 1); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:i: ", p), err) }
    if err := oprot.WriteI32(int32(*p.I)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.i (1) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 1:i: ", p), err) }
  }
  return err
}

func (p *Union1) writeField2(oprot thrift.TProtocol) (err error) {
  if p.IsSetD() {
    if err := oprot.WriteFieldBegin("d", thrift.DOUBLE, 2); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:d: ", p), err) }
    if err := oprot.WriteDouble(float64(*p.D)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.d (2) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 2:d: ", p), err) }
  }
  return err
}

func (p *Union1) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Union1(%+v)", *p)
}

// Attributes:
//  - I
//  - D
//  - S
//  - U
type Union2 struct {
  I *int32 `thrift:"i,1" db:"i" json:"i,omitempty"`
  D *float64 `thrift:"d,2" db:"d" json:"d,omitempty"`
  S *Struct1 `thrift:"s,3" db:"s" json:"s,omitempty"`
  U *Union1 `thrift:"u,4" db:"u" json:"u,omitempty"`
}

func NewUnion2() *Union2 {
  return &Union2{}
}

var Union2_I_DEFAULT int32
func (p *Union2) GetI() int32 {
  if !p.IsSetI() {
    return Union2_I_DEFAULT
  }
return *p.I
}
var Union2_D_DEFAULT float64
func (p *Union2) GetD() float64 {
  if !p.IsSetD() {
    return Union2_D_DEFAULT
  }
return *p.D
}
var Union2_S_DEFAULT *Struct1
func (p *Union2) GetS() *Struct1 {
  if !p.IsSetS() {
    return Union2_S_DEFAULT
  }
return p.S
}
var Union2_U_DEFAULT *Union1
func (p *Union2) GetU() *Union1 {
  if !p.IsSetU() {
    return Union2_U_DEFAULT
  }
return p.U
}
func (p *Union2) CountSetFieldsUnion2() int {
  count := 0
  if (p.IsSetI()) {
    count++
  }
  if (p.IsSetD()) {
    count++
  }
  if (p.IsSetS()) {
    count++
  }
  if (p.IsSetU()) {
    count++
  }
  return count

}

func (p *Union2) IsSetI() bool {
  return p.I != nil
}

func (p *Union2) IsSetD() bool {
  return p.D != nil
}

func (p *Union2) IsSetS() bool {
  return p.S != nil
}

func (p *Union2) IsSetU() bool {
  return p.U != nil
}

func (p *Union2) Read(iprot thrift.TProtocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Union2)  ReadField1(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.I = &v
}
  return nil
}

func (p *Union2)  ReadField2(iprot thrift.TProtocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.D = &v
}
  return nil
}

func (p *Union2)  ReadField3(iprot thrift.TProtocol) error {
  p.S = NewStruct1()
  if err := p.S.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.S), err)
  }
  return nil
}

func (p *Union2)  ReadField4(iprot thrift.TProtocol) error {
  p.U = NewUnion1()
  if err := p.U.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.U), err)
  }
  return nil
}

func (p *Union2) Write(oprot thrift.TProtocol) error {
  if c := p.CountSetFieldsUnion2(); c != 1 {
    return fmt.Errorf("%T write union: exactly one field must be set (%d set).", p, c)
  }
  if err := oprot.WriteStructBegin("union2"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Union2) writeField1(oprot thrift.TProtocol) (err error) {
  if p.IsSetI() {
    if err := oprot.WriteFieldBegin("i", thrift.I32, 1); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:i: ", p), err) }
    if err := oprot.WriteI32(int32(*p.I)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.i (1) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 1:i: ", p), err) }
  }
  return err
}

func (p *Union2) writeField2(oprot thrift.TProtocol) (err error) {
  if p.IsSetD() {
    if err := oprot.WriteFieldBegin("d", thrift.DOUBLE, 2); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:d: ", p), err) }
    if err := oprot.WriteDouble(float64(*p.D)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.d (2) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 2:d: ", p), err) }
  }
  return err
}

func (p *Union2) writeField3(oprot thrift.TProtocol) (err error) {
  if p.IsSetS() {
    if err := oprot.WriteFieldBegin("s", thrift.STRUCT, 3); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:s: ", p), err) }
    if err := p.S.Write(oprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.S), err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 3:s: ", p), err) }
  }
  return err
}

func (p *Union2) writeField4(oprot thrift.TProtocol) (err error) {
  if p.IsSetU() {
    if err := oprot.WriteFieldBegin("u", thrift.STRUCT, 4); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:u: ", p), err) }
    if err := p.U.Write(oprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.U), err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 4:u: ", p), err) }
  }
  return err
}

func (p *Union2) String() string {
  if p == nil {
    return "<nil>"
  }
  return fmt.Sprintf("Union2(%+v)", *p)
}

