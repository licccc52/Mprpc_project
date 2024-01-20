// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto;
class LoginRequest;
struct LoginRequestDefaultTypeInternal;
extern LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
class LoginResponse;
struct LoginResponseDefaultTypeInternal;
extern LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::LoginRequest* Arena::CreateMaybeMessage<::LoginRequest>(Arena*);
template<> ::LoginResponse* Arena::CreateMaybeMessage<::LoginResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class LoginRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:LoginRequest) */ {
 public:
  inline LoginRequest() : LoginRequest(nullptr) {}
  ~LoginRequest() override;
  explicit constexpr LoginRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginRequest(const LoginRequest& from);
  LoginRequest(LoginRequest&& from) noexcept
    : LoginRequest() {
    *this = ::std::move(from);
  }

  inline LoginRequest& operator=(const LoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginRequest& operator=(LoginRequest&& from) noexcept {
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
  static const LoginRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginRequest* internal_default_instance() {
    return reinterpret_cast<const LoginRequest*>(
               &_LoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LoginRequest& a, LoginRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginRequest* other) {
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
  void UnsafeArenaSwap(LoginRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LoginRequest& from);
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
  void InternalSwap(LoginRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "LoginRequest";
  }
  protected:
  explicit LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kPwdFieldNumber = 2,
  };
  // bytes name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // bytes pwd = 2;
  void clear_pwd();
  const std::string& pwd() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pwd(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pwd();
  PROTOBUF_NODISCARD std::string* release_pwd();
  void set_allocated_pwd(std::string* pwd);
  private:
  const std::string& _internal_pwd() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pwd(const std::string& value);
  std::string* _internal_mutable_pwd();
  public:

  // @@protoc_insertion_point(class_scope:LoginRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pwd_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_test_2eproto;
};
// -------------------------------------------------------------------

class LoginResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:LoginResponse) */ {
 public:
  inline LoginResponse() : LoginResponse(nullptr) {}
  ~LoginResponse() override;
  explicit constexpr LoginResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginResponse(const LoginResponse& from);
  LoginResponse(LoginResponse&& from) noexcept
    : LoginResponse() {
    *this = ::std::move(from);
  }

  inline LoginResponse& operator=(const LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginResponse& operator=(LoginResponse&& from) noexcept {
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
  static const LoginResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginResponse* internal_default_instance() {
    return reinterpret_cast<const LoginResponse*>(
               &_LoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LoginResponse& a, LoginResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginResponse* other) {
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
  void UnsafeArenaSwap(LoginResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LoginResponse& from);
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
  void InternalSwap(LoginResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "LoginResponse";
  }
  protected:
  explicit LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrcodeFieldNumber = 1,
    kSuccessFieldNumber = 3,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_errmsg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_errmsg();
  PROTOBUF_NODISCARD std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // int32 errcode = 1;
  void clear_errcode();
  int32_t errcode() const;
  void set_errcode(int32_t value);
  private:
  int32_t _internal_errcode() const;
  void _internal_set_errcode(int32_t value);
  public:

  // bool success = 3;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:LoginResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  int32_t errcode_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_test_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LoginRequest

// bytes name = 1;
inline void LoginRequest::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& LoginRequest::name() const {
  // @@protoc_insertion_point(field_get:LoginRequest.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:LoginRequest.name)
}
inline std::string* LoginRequest::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:LoginRequest.name)
  return _s;
}
inline const std::string& LoginRequest::_internal_name() const {
  return name_.Get();
}
inline void LoginRequest::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LoginRequest::release_name() {
  // @@protoc_insertion_point(field_release:LoginRequest.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LoginRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:LoginRequest.name)
}

// bytes pwd = 2;
inline void LoginRequest::clear_pwd() {
  pwd_.ClearToEmpty();
}
inline const std::string& LoginRequest::pwd() const {
  // @@protoc_insertion_point(field_get:LoginRequest.pwd)
  return _internal_pwd();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_pwd(ArgT0&& arg0, ArgT... args) {
 
 pwd_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:LoginRequest.pwd)
}
inline std::string* LoginRequest::mutable_pwd() {
  std::string* _s = _internal_mutable_pwd();
  // @@protoc_insertion_point(field_mutable:LoginRequest.pwd)
  return _s;
}
inline const std::string& LoginRequest::_internal_pwd() const {
  return pwd_.Get();
}
inline void LoginRequest::_internal_set_pwd(const std::string& value) {
  
  pwd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_pwd() {
  
  return pwd_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LoginRequest::release_pwd() {
  // @@protoc_insertion_point(field_release:LoginRequest.pwd)
  return pwd_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LoginRequest::set_allocated_pwd(std::string* pwd) {
  if (pwd != nullptr) {
    
  } else {
    
  }
  pwd_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pwd,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (pwd_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    pwd_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:LoginRequest.pwd)
}

// -------------------------------------------------------------------

// LoginResponse

// int32 errcode = 1;
inline void LoginResponse::clear_errcode() {
  errcode_ = 0;
}
inline int32_t LoginResponse::_internal_errcode() const {
  return errcode_;
}
inline int32_t LoginResponse::errcode() const {
  // @@protoc_insertion_point(field_get:LoginResponse.errcode)
  return _internal_errcode();
}
inline void LoginResponse::_internal_set_errcode(int32_t value) {
  
  errcode_ = value;
}
inline void LoginResponse::set_errcode(int32_t value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:LoginResponse.errcode)
}

// bytes errmsg = 2;
inline void LoginResponse::clear_errmsg() {
  errmsg_.ClearToEmpty();
}
inline const std::string& LoginResponse::errmsg() const {
  // @@protoc_insertion_point(field_get:LoginResponse.errmsg)
  return _internal_errmsg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginResponse::set_errmsg(ArgT0&& arg0, ArgT... args) {
 
 errmsg_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:LoginResponse.errmsg)
}
inline std::string* LoginResponse::mutable_errmsg() {
  std::string* _s = _internal_mutable_errmsg();
  // @@protoc_insertion_point(field_mutable:LoginResponse.errmsg)
  return _s;
}
inline const std::string& LoginResponse::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void LoginResponse::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LoginResponse::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LoginResponse::release_errmsg() {
  // @@protoc_insertion_point(field_release:LoginResponse.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LoginResponse::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (errmsg_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:LoginResponse.errmsg)
}

// bool success = 3;
inline void LoginResponse::clear_success() {
  success_ = false;
}
inline bool LoginResponse::_internal_success() const {
  return success_;
}
inline bool LoginResponse::success() const {
  // @@protoc_insertion_point(field_get:LoginResponse.success)
  return _internal_success();
}
inline void LoginResponse::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void LoginResponse::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:LoginResponse.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_2eproto
