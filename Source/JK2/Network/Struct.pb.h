// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace message {
class ObjectInfo;
struct ObjectInfoDefaultTypeInternal;
extern ObjectInfoDefaultTypeInternal _ObjectInfo_default_instance_;
class PosInfo;
struct PosInfoDefaultTypeInternal;
extern PosInfoDefaultTypeInternal _PosInfo_default_instance_;
}  // namespace message
PROTOBUF_NAMESPACE_OPEN
template<> ::message::ObjectInfo* Arena::CreateMaybeMessage<::message::ObjectInfo>(Arena*);
template<> ::message::PosInfo* Arena::CreateMaybeMessage<::message::PosInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace message {

// ===================================================================

class PosInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:message.PosInfo) */ {
 public:
  inline PosInfo() : PosInfo(nullptr) {}
  ~PosInfo() override;
  explicit PROTOBUF_CONSTEXPR PosInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PosInfo(const PosInfo& from);
  PosInfo(PosInfo&& from) noexcept
    : PosInfo() {
    *this = ::std::move(from);
  }

  inline PosInfo& operator=(const PosInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PosInfo& operator=(PosInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PosInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const PosInfo* internal_default_instance() {
    return reinterpret_cast<const PosInfo*>(
               &_PosInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PosInfo& a, PosInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(PosInfo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PosInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PosInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PosInfo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PosInfo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PosInfo& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PosInfo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "message.PosInfo";
  }
  protected:
  explicit PosInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kObjectIdFieldNumber = 1,
    kXFieldNumber = 2,
    kYFieldNumber = 3,
    kZFieldNumber = 4,
    kYawFieldNumber = 5,
    kStateFieldNumber = 6,
  };
  // uint64 object_id = 1;
  void clear_object_id();
  uint64_t object_id() const;
  void set_object_id(uint64_t value);
  private:
  uint64_t _internal_object_id() const;
  void _internal_set_object_id(uint64_t value);
  public:

  // float x = 2;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 3;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float z = 4;
  void clear_z();
  float z() const;
  void set_z(float value);
  private:
  float _internal_z() const;
  void _internal_set_z(float value);
  public:

  // float yaw = 5;
  void clear_yaw();
  float yaw() const;
  void set_yaw(float value);
  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);
  public:

  // .message.MoveState state = 6;
  void clear_state();
  ::message::MoveState state() const;
  void set_state(::message::MoveState value);
  private:
  ::message::MoveState _internal_state() const;
  void _internal_set_state(::message::MoveState value);
  public:

  // @@protoc_insertion_point(class_scope:message.PosInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  uint64_t object_id_;
  float x_;
  float y_;
  float z_;
  float yaw_;
  int state_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// -------------------------------------------------------------------

class ObjectInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:message.ObjectInfo) */ {
 public:
  inline ObjectInfo() : ObjectInfo(nullptr) {}
  ~ObjectInfo() override;
  explicit PROTOBUF_CONSTEXPR ObjectInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ObjectInfo(const ObjectInfo& from);
  ObjectInfo(ObjectInfo&& from) noexcept
    : ObjectInfo() {
    *this = ::std::move(from);
  }

  inline ObjectInfo& operator=(const ObjectInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline ObjectInfo& operator=(ObjectInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ObjectInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const ObjectInfo* internal_default_instance() {
    return reinterpret_cast<const ObjectInfo*>(
               &_ObjectInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ObjectInfo& a, ObjectInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(ObjectInfo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ObjectInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ObjectInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ObjectInfo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ObjectInfo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ObjectInfo& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ObjectInfo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "message.ObjectInfo";
  }
  protected:
  explicit ObjectInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPosInfoFieldNumber = 3,
    kObjectIdFieldNumber = 1,
    kObjectTypeFieldNumber = 2,
  };
  // .message.PosInfo pos_info = 3;
  bool has_pos_info() const;
  private:
  bool _internal_has_pos_info() const;
  public:
  void clear_pos_info();
  const ::message::PosInfo& pos_info() const;
  PROTOBUF_NODISCARD ::message::PosInfo* release_pos_info();
  ::message::PosInfo* mutable_pos_info();
  void set_allocated_pos_info(::message::PosInfo* pos_info);
  private:
  const ::message::PosInfo& _internal_pos_info() const;
  ::message::PosInfo* _internal_mutable_pos_info();
  public:
  void unsafe_arena_set_allocated_pos_info(
      ::message::PosInfo* pos_info);
  ::message::PosInfo* unsafe_arena_release_pos_info();

  // uint64 object_id = 1;
  void clear_object_id();
  uint64_t object_id() const;
  void set_object_id(uint64_t value);
  private:
  uint64_t _internal_object_id() const;
  void _internal_set_object_id(uint64_t value);
  public:

  // .message.ObjectType object_type = 2;
  void clear_object_type();
  ::message::ObjectType object_type() const;
  void set_object_type(::message::ObjectType value);
  private:
  ::message::ObjectType _internal_object_type() const;
  void _internal_set_object_type(::message::ObjectType value);
  public:

  // @@protoc_insertion_point(class_scope:message.ObjectInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::message::PosInfo* pos_info_;
  uint64_t object_id_;
  int object_type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PosInfo

// uint64 object_id = 1;
inline void PosInfo::clear_object_id() {
  object_id_ = uint64_t{0u};
}
inline uint64_t PosInfo::_internal_object_id() const {
  return object_id_;
}
inline uint64_t PosInfo::object_id() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.object_id)
  return _internal_object_id();
}
inline void PosInfo::_internal_set_object_id(uint64_t value) {
  
  object_id_ = value;
}
inline void PosInfo::set_object_id(uint64_t value) {
  _internal_set_object_id(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.object_id)
}

// float x = 2;
inline void PosInfo::clear_x() {
  x_ = 0;
}
inline float PosInfo::_internal_x() const {
  return x_;
}
inline float PosInfo::x() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.x)
  return _internal_x();
}
inline void PosInfo::_internal_set_x(float value) {
  
  x_ = value;
}
inline void PosInfo::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.x)
}

// float y = 3;
inline void PosInfo::clear_y() {
  y_ = 0;
}
inline float PosInfo::_internal_y() const {
  return y_;
}
inline float PosInfo::y() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.y)
  return _internal_y();
}
inline void PosInfo::_internal_set_y(float value) {
  
  y_ = value;
}
inline void PosInfo::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.y)
}

// float z = 4;
inline void PosInfo::clear_z() {
  z_ = 0;
}
inline float PosInfo::_internal_z() const {
  return z_;
}
inline float PosInfo::z() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.z)
  return _internal_z();
}
inline void PosInfo::_internal_set_z(float value) {
  
  z_ = value;
}
inline void PosInfo::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.z)
}

// float yaw = 5;
inline void PosInfo::clear_yaw() {
  yaw_ = 0;
}
inline float PosInfo::_internal_yaw() const {
  return yaw_;
}
inline float PosInfo::yaw() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.yaw)
  return _internal_yaw();
}
inline void PosInfo::_internal_set_yaw(float value) {
  
  yaw_ = value;
}
inline void PosInfo::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.yaw)
}

// .message.MoveState state = 6;
inline void PosInfo::clear_state() {
  state_ = 0;
}
inline ::message::MoveState PosInfo::_internal_state() const {
  return static_cast< ::message::MoveState >(state_);
}
inline ::message::MoveState PosInfo::state() const {
  // @@protoc_insertion_point(field_get:message.PosInfo.state)
  return _internal_state();
}
inline void PosInfo::_internal_set_state(::message::MoveState value) {
  
  state_ = value;
}
inline void PosInfo::set_state(::message::MoveState value) {
  _internal_set_state(value);
  // @@protoc_insertion_point(field_set:message.PosInfo.state)
}

// -------------------------------------------------------------------

// ObjectInfo

// uint64 object_id = 1;
inline void ObjectInfo::clear_object_id() {
  object_id_ = uint64_t{0u};
}
inline uint64_t ObjectInfo::_internal_object_id() const {
  return object_id_;
}
inline uint64_t ObjectInfo::object_id() const {
  // @@protoc_insertion_point(field_get:message.ObjectInfo.object_id)
  return _internal_object_id();
}
inline void ObjectInfo::_internal_set_object_id(uint64_t value) {
  
  object_id_ = value;
}
inline void ObjectInfo::set_object_id(uint64_t value) {
  _internal_set_object_id(value);
  // @@protoc_insertion_point(field_set:message.ObjectInfo.object_id)
}

// .message.ObjectType object_type = 2;
inline void ObjectInfo::clear_object_type() {
  object_type_ = 0;
}
inline ::message::ObjectType ObjectInfo::_internal_object_type() const {
  return static_cast< ::message::ObjectType >(object_type_);
}
inline ::message::ObjectType ObjectInfo::object_type() const {
  // @@protoc_insertion_point(field_get:message.ObjectInfo.object_type)
  return _internal_object_type();
}
inline void ObjectInfo::_internal_set_object_type(::message::ObjectType value) {
  
  object_type_ = value;
}
inline void ObjectInfo::set_object_type(::message::ObjectType value) {
  _internal_set_object_type(value);
  // @@protoc_insertion_point(field_set:message.ObjectInfo.object_type)
}

// .message.PosInfo pos_info = 3;
inline bool ObjectInfo::_internal_has_pos_info() const {
  return this != internal_default_instance() && pos_info_ != nullptr;
}
inline bool ObjectInfo::has_pos_info() const {
  return _internal_has_pos_info();
}
inline void ObjectInfo::clear_pos_info() {
  if (GetArenaForAllocation() == nullptr && pos_info_ != nullptr) {
    delete pos_info_;
  }
  pos_info_ = nullptr;
}
inline const ::message::PosInfo& ObjectInfo::_internal_pos_info() const {
  const ::message::PosInfo* p = pos_info_;
  return p != nullptr ? *p : reinterpret_cast<const ::message::PosInfo&>(
      ::message::_PosInfo_default_instance_);
}
inline const ::message::PosInfo& ObjectInfo::pos_info() const {
  // @@protoc_insertion_point(field_get:message.ObjectInfo.pos_info)
  return _internal_pos_info();
}
inline void ObjectInfo::unsafe_arena_set_allocated_pos_info(
    ::message::PosInfo* pos_info) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(pos_info_);
  }
  pos_info_ = pos_info;
  if (pos_info) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:message.ObjectInfo.pos_info)
}
inline ::message::PosInfo* ObjectInfo::release_pos_info() {
  
  ::message::PosInfo* temp = pos_info_;
  pos_info_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::message::PosInfo* ObjectInfo::unsafe_arena_release_pos_info() {
  // @@protoc_insertion_point(field_release:message.ObjectInfo.pos_info)
  
  ::message::PosInfo* temp = pos_info_;
  pos_info_ = nullptr;
  return temp;
}
inline ::message::PosInfo* ObjectInfo::_internal_mutable_pos_info() {
  
  if (pos_info_ == nullptr) {
    auto* p = CreateMaybeMessage<::message::PosInfo>(GetArenaForAllocation());
    pos_info_ = p;
  }
  return pos_info_;
}
inline ::message::PosInfo* ObjectInfo::mutable_pos_info() {
  ::message::PosInfo* _msg = _internal_mutable_pos_info();
  // @@protoc_insertion_point(field_mutable:message.ObjectInfo.pos_info)
  return _msg;
}
inline void ObjectInfo::set_allocated_pos_info(::message::PosInfo* pos_info) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete pos_info_;
  }
  if (pos_info) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(pos_info);
    if (message_arena != submessage_arena) {
      pos_info = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, pos_info, submessage_arena);
    }
    
  } else {
    
  }
  pos_info_ = pos_info;
  // @@protoc_insertion_point(field_set_allocated:message.ObjectInfo.pos_info)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
