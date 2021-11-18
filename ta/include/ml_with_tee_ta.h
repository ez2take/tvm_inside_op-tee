#ifndef TA_ML_WITH_TEE_H
#define TA_ML_WITH_TEE_H


/*
 * This UUID is generated with uuidgen
 * the ITU-T UUID generator at http://www.itu.int/ITU-T/asn1/uuid.html
 */


#define TA_ML_WITH_TEE_UUID \
	{ 0x9d4b104f, 0x840c, 0x431b, \ 
		{ 0xba, 0x18, 0x01, 0xf7, 0x53, 0x4f, 0x5c, 0xe8} }
/* The function IDs implemented in this TA */
#define TA_ML_WITH_TEE_CMD_TVMModCreateFromCModule		0
#define TA_ML_WITH_TEE_CMD_LoadModelGraphJson		    1 
#define TA_ML_WITH_TEE_CMD_LoadModelParamBlob		    2
#define TA_ML_WITH_TEE_CMD_TVMGraphExecutor_SetInput	4
#define TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Run		    3
#define TA_ML_WITH_TEE_CMD_TVMGraphExecutor_GetOutput	4
#define TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Release		5

#endif /*TA_ML_WITH_TEE_H*/
