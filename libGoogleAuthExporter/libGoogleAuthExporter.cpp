#include "libGoogleAuthExporter.h"
#include "google_auth.pb.h"
#include "base64_rfc4648.hpp"
#include "base32_rfc4648.hpp"

using namespace googleauth;
LIBGOOGLEAUTHEXPORTER_API int GAuthExporter_Decode(const char* szInput, char* szOutput, int* nLen)
{
	if (szInput == NULL || nLen == NULL)
		return ERR_INVALID_ARGUMENT;

//#step1:base64 decode input
	std::vector<uint8_t> vecDecoded = cppcodec::base64_rfc4648::decode(szInput,strlen(szInput));
	if (vecDecoded.size() <= 0)
		return ERR_DECODEDBASE64_FAILED;
//#step2:analyze protobuf
	MigrationPayload payload;
	bool bOK = payload.ParseFromArray((const void*)(&(vecDecoded[0])),vecDecoded.size());
	if (!bOK)
		return ERR_PARSEPROTOBUF_FAILED;
	if(payload.otp_parameters_size() <= 0 )
		return ERR_NO_OPT_PARAMS;

	const std::string& strSecret = payload.otp_parameters(0).secret();
	std::string strB32Enc = cppcodec::base32_rfc4648::encode(strSecret.c_str(), strSecret.size());
	if (*nLen >= (int)strB32Enc.size() && szOutput)
	{
#ifdef WIN32
		strncpy_s(szOutput, *nLen, strB32Enc.c_str(), strB32Enc.size());
#else
		strncpy(szOutput, strB32Enc.c_str(), strB32Enc.size());
#endif
	}
	*nLen = strB32Enc.size();
	return 0;
}

