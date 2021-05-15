# libGoogleAuthExporter

an c++ implement of google-authenticator-exporter https://github.com/yi-ge/google-authenticator-exporter

Compile under VS2019 passed

protobuf include&lib not upload, you can manually include or install from [vcpkg](https://github.com/Microsoft/vcpkg).

using cppcodec as Base32/Base64 encode/decode
  https://github.com/tplgy/cppcodec ,as a result, it require C11 support.

# Usage

see TestGoogleAuthExporter as reference.
just include libGoogleAuthExporter.h


# Test
you can run TestGoogleAuthExporter which in binary folder (or you can compile it) with args.

For example:

you got an encrypt data like this:

otpauth-migration://offline?data=Ci8KHuS9nOiAhSA3aWFu5aSn5ZyjIHFxIDU0MTk4MDIwMBIHS2luaEtleSABKAEwAhAB

Run Like this:
```
TestGoogleAuthExporter Ci8KHuS9nOiAhSA3aWFu5aSn5ZyjIHFxIDU0MTk4MDIwMBIHS2luaEtleSABKAEwAhAB
```

And you will get display like this:
```
4S6ZZ2EAQUQDO2LBN3S2JJ7FTSRSA4LREA2TIMJZHAYDEMBQ
```

