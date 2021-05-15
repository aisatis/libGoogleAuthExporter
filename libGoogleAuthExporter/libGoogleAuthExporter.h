#ifndef libGoogleAuthExporter_h__
#define libGoogleAuthExporter_h__


#ifdef WIN32
#ifdef LIBGOOGLEAUTHEXPORTER_EXPORTS
#define LIBGOOGLEAUTHEXPORTER_API __declspec(dllexport)
#else
#define LIBGOOGLEAUTHEXPORTER_API __declspec(dllimport)
#endif
#else
#define LIBGOOGLEAUTHEXPORTER_API  
#endif

//[ret] 0=ok,<0 = errcode
//[szInput] input encrypt data with null terminated
//[szOutput] output decrypt data with max [nLen] defined. if szOutput is NULL or len is not enough,only len will return.
//[nLen] len with null terminated

LIBGOOGLEAUTHEXPORTER_API int GAuthExporter_Decode(const char* szInput, char* szOutput, int* nLen);


#define ERR_UNKNOWN -1
#define ERR_INVALID_ARGUMENT -2
#define ERR_DECODEDBASE64_FAILED -10
#define ERR_PARSEPROTOBUF_FAILED -11
#define ERR_NO_OPT_PARAMS -11

#endif // libGoogleAuthExporter_h__
