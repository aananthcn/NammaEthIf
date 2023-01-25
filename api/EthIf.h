/*
 * Created on Mon Jan 23 2023 9:48:13 PM
 *
 * The MIT License(MIT)
 * Copyright(c) 2023 Aananth C N
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files(the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef NAMMA_AUTOSAR_ETH_IF_H
#define NAMMA_AUTOSAR_ETH_IF_H

#include <stddef.h>

#include <Platform_Types.h>
#include <Std_Types.h>

#include <Eth.h>
#include <EthIf_cfg.h>
#include <Eth_GeneralTypes.h>
#include <ComStack_Types.h>
#include <EcuM.h>


// EthIf types
typedef uint8 EthIf_SwitchPortGroupIdxType;
typedef uint8 EthIf_MeasurementIdxType;
typedef uint32 EthIf_SignalQualityResultType;


// function prototypes
void EthIf_Init(const EthIf_ConfigType* CfgPtr);
Std_ReturnType EthIf_SetControllerMode(uint8 CtrlIdx, Eth_ModeType CtrlMode);
Std_ReturnType EthIf_GetControllerMode(uint8 CtrlIdx, Eth_ModeType* CtrlModePtr);
Std_ReturnType EthIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType EthIf_GetPhyWakeupReason(uint8 TrcvIdx, EthTrcv_WakeupReasonType* WakeupReasonPtr);
Std_ReturnType EthIf_GetSwitchPortWakeupReason(uint8 SwitchIdx, uint8 SwitchPortIdx,
	EthTrcv_WakeupReasonType* WakeupReasonPtr);
void EthIf_GetPhysAddr(uint8 CtrlIdx, uint8* PhysAddrPtr);
void EthIf_SetPhysAddr(uint8 CtrlIdx, const uint8* PhysAddrPtr);
Std_ReturnType EthIf_UpdatePhysAddrFilter(uint8 CtrlIdx, const uint8* PhysAddrPtr, Eth_FilterActionType Action);
Std_ReturnType EthIf_GetPortMacAddr(const uint8* MacAddrPtr, uint8* SwitchIdxPtr, uint8* PortIdxPtr);
Std_ReturnType EthIf_GetArlTable(uint8 switchIdx, uint16* numberOfElements,  Eth_MacVlanType* arlTableListPointer);
Std_ReturnType EthIf_GetCtrlIdxList(uint8* NumberOfCtrlIdx, uint8* CtrlIdxListPtr);
Std_ReturnType EthIf_GetVlanId(uint8 CtrlIdx, uint16* VlanIdPtr);
Std_ReturnType EthIf_GetAndResetMeasurementData(EthIf_MeasurementIdxType MeasurementIdx,
	boolean MeasurementResetNeeded, uint32* MeasurementDataPtr);
Std_ReturnType EthIf_StoreConfiguration(uint8 SwitchIdx);
Std_ReturnType EthIf_ResetConfiguration(uint8 SwitchIdx);
Std_ReturnType EthIf_GetCurrentTime(uint8 CtrlIdx, Eth_TimeStampQualType* timeQualPtr,
	Eth_TimeStampType* timeStampPtr);
void EthIf_EnableEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx);
Std_ReturnType EthIf_GetEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx,
	Eth_TimeStampQualType* timeQualPtr, Eth_TimeStampType* timeStampPtr);
Std_ReturnType EthIf_GetIngressTimeStamp(uint8 CtrlIdx, const Eth_DataType* DataPtr,
	Eth_TimeStampQualType* timeQualPtr, Eth_TimeStampType* timeStampPtr);
Std_ReturnType EthIf_SwitchPortGroupRequestMode(EthIf_SwitchPortGroupIdxType PortGroupIdx,
	Eth_ModeType PortMode);
Std_ReturnType EthIf_StartAllPorts(void);
Std_ReturnType EthIf_SetSwitchMgmtInfo(uint8 CtrlIdx, Eth_BufIdxType BufIdx, EthSwt_MgmtInfoType* MgmtInfoPtr);
Std_ReturnType EthIf_GetRxMgmtObject(uint8 CtrlIdx, Eth_DataType* DataPtr, EthSwt_MgmtObjectType **MgmtObjectPtr);
Std_ReturnType EthIf_GetTxMgmtObject(uint8 CtrlIdx, Eth_BufIdxType BufIdx, EthSwt_MgmtObjectType **MgmtObjectPtr);
Std_ReturnType EthIf_SwitchEnableTimeStamping(uint8 CtrlIdx, Eth_BufIdxType BufIdx, EthSwt_MgmtInfoType* MgmtInfo);
Std_ReturnType EthIf_VerifyConfig(uint8 SwitchIdx, boolean*  Result);
Std_ReturnType EthIf_SetForwardingMode(uint8 SwitchIdx, boolean mode);
Std_ReturnType EthIf_GetTrcvSignalQuality(uint8 TrcvIdx, EthIf_SignalQualityResultType* ResultPtr);
Std_ReturnType EthIf_GetSwitchPortSignalQuality(uint8 SwitchIdx, uint8 SwitchPortIdx,
	EthIf_SignalQualityResultType* ResultPtr);
Std_ReturnType EthIf_ClearTrcvSignalQuality(uint8 TrcvIdx);
Std_ReturnType EthIf_ClearSwitchPortSignalQuality(uint8 SwitchIdx, uint8 SwitchPortIdx);
Std_ReturnType EthIf_SetPhyTestMode(uint8 TrcvIdx, EthTrcv_PhyTestModeType Mode);
Std_ReturnType EthIf_SetPhyLoopbackMode(uint8 TrcvIdx, EthTrcv_PhyLoopbackModeType Mode);
Std_ReturnType EthIf_SetPhyTxMode(uint8 TrcvIdx, EthTrcv_PhyTxModeType Mode);
Std_ReturnType EthIf_GetCableDiagnosticsResult(uint8 TrcvIdx, EthTrcv_CableDiagResultType* ResultPtr);
Std_ReturnType EthIf_GetPhyIdentifier(uint8 TrcvIdx, uint32* OrgUniqueIdPtr,
	uint8 *ModelNrPtr, uint8* RevisionNrPtr);

#if 0
Std_ReturnType EthIf_GetBufWRxParams(uint8 CtrlIdx, const WEth_BufWRxParamIdType* RxParamIds,
	uint32* ParamValues, uint8 NumParams);
Std_ReturnType EthIf_GetBufWTxParams(uint8 CtrlIdx, const WEth_BufWTxParamIdType* TxParamIds,
	uint32* ParamValues, uint8 NumParams);
Std_ReturnType EthIf_SetBufWTxParams(uint8 CtrlIdx, Eth_BufIdxType BufIdx,
	const WEth_BufWTxParamIdType* TxParamIds, const uint32* ParamValues, uint8 NumParams);
Std_ReturnType EthIf_SetRadioParams(uint8 TrcvId, const WEthTrcv_SetRadioParamIdType* ParamIds,
	const uint32* ParamValue, uint8 NumParams);
Std_ReturnType EthIf_SetChanRxParams(uint8 TrcvId, uint8 RadioId,
	const WEthTrcv_SetChanRxParamIdType* ParamIds, const uint32* ParamValues, uint8 NumParams);
Std_ReturnType EthIf_SetChanTxParams(uint8 TrcvId, uint8 RadioId,
	const WEthTrcv_SetChanTxParamIdType* TxParamIds, const uint32* ParamValues, uint8 NumParams);
Std_ReturnType EthIf_GetChanRxParams(uint8 TrcvId, uint8 RadioId,
	const WEthTrcv_GetChanRxParamIdType* ParamIds, uint32* ParamValues, uint8 NumParams);
#endif

BufReq_ReturnType EthIf_ProvideTxBuffer(uint8 CtrlIdx, Eth_FrameType FrameType,
	uint8 Priority,  Eth_BufIdxType* BufIdxPtr, uint8** BufPtr, uint16* LenBytePtr);

Std_ReturnType EthIf_Transmit(uint8 CtrlIdx, Eth_BufIdxType BufIdx,
	Eth_FrameType FrameType, boolean TxConfirmation,  uint16 LenByte, const uint8* PhysAddrPtr);
void EthIf_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);
Std_ReturnType EthIf_GetSwitchPortMode(uint8 SwitchIdx, uint8 SwitchPortIdx, Eth_ModeType* PortModePtr);
Std_ReturnType EthIf_GetTransceiverMode(uint8 TrcvIdx, Eth_ModeType* TrcvModePtr);
Std_ReturnType EthIf_SwitchPortGetLinkState(uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_LinkStateType* LinkStatePtr);
Std_ReturnType EthIf_TransceiverGetLinkState(uint8 TrcvIdx, EthTrcv_LinkStateType* LinkStatePtr);
Std_ReturnType EthIf_SwitchPortGetBaudRate(uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_BaudRateType* BaudRatePtr);
Std_ReturnType EthIf_TransceiverGetBaudRate(uint8 TrcvIdx, EthTrcv_BaudRateType* BaudRatePtr);
Std_ReturnType EthIf_SwitchPortGetDuplexMode(uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_DuplexModeType* DuplexModePtr);
Std_ReturnType EthIf_TransceiverGetDuplexMode(uint8 TrcvIdx, EthTrcv_DuplexModeType* DuplexModePtr);
Std_ReturnType EthIf_SwitchPortGetCounterValues(uint8 SwitchIdx, uint8 SwitchPortIdx, Eth_CounterType* CounterPtr);
Std_ReturnType EthIf_SwitchPortGetRxStats(uint8 SwitchIdx, uint8 SwitchPortIdx, Eth_RxStatsType* RxStatsPtr);
Std_ReturnType EthIf_SwitchPortGetTxStats(uint8 SwitchIdx, uint8 SwitchPortIdx, Eth_TxStatsType* TxStatsPtr);
Std_ReturnType EthIf_SwitchPortGetTxErrorCounterValues(uint8 SwitchIdx, uint8 SwitchPortIdx,
	Eth_TxErrorCounterValuesType* TxStatsPtr);
Std_ReturnType EthIf_SwitchPortGetMacLearningMode(uint8 SwitchIdx, uint8 SwitchPortIdx,
	EthSwt_MacLearningType* MacLearningModePtr);
Std_ReturnType EthIf_GetSwitchPortIdentifier(uint8 SwitchIdx, uint8 SwitchPortIdx,
	uint32* OrgUniqueIdPtr, uint8*ModelNrPtr, uint8* RevisionNrPtr);
Std_ReturnType EthIf_GetSwitchIdentifier(uint8 SwitchIdx, uint32* OrgUniqueIdPtr);
Std_ReturnType EthIf_WritePortMirrorConfiguration(uint8 MirroredSwitchIdx,
	const EthSwt_PortMirrorCfgType* PortMirrorConfigurationPtr);
Std_ReturnType EthIf_ReadPortMirrorConfiguration(uint8 MirroredSwitchIdx,
	EthSwt_PortMirrorCfgType* PortMirrorConfigurationPtr);
Std_ReturnType EthIf_DeletePortMirrorConfiguration(uint8 MirroredSwitchIdx);
Std_ReturnType EthIf_GetPortMirrorState(uint8 SwitchIdx, uint8 PortIdx, EthSwt_PortMirrorStateType* PortMirrorStatePtr);
Std_ReturnType EthIf_SetPortMirrorState(uint8 MirroredSwitchIdx, uint8 PortIdx, EthSwt_PortMirrorStateType PortMirrorState);
Std_ReturnType EthIf_SetPortTestMode(uint8 SwitchIdx, uint8 PortIdx, EthTrcv_PhyTestModeType Mode);
Std_ReturnType EthIf_SetPortLoopbackMode(uint8 SwitchIdx, uint8 PortIdx, EthTrcv_PhyLoopbackModeType Mode);
Std_ReturnType EthIf_SetPortTxMode(uint8 SwitchIdx, uint8 PortIdx, EthTrcv_PhyTxModeType Mode);
Std_ReturnType EthIf_GetPortCableDiagnosticsResult(uint8 SwitchIdx, uint8 PortIdx, EthTrcv_CableDiagResultType* ResultPtr);
Std_ReturnType EthIf_RunPortCableDiagnostic(uint8 SwitchIdx, uint8 PortIdx);
Std_ReturnType EthIf_RunCableDiagnostic(uint8 TrcvIdx);
Std_ReturnType EthIf_SwitchGetCfgDataRaw(uint8 SwitchIdx, uint32 Offset, uint16 Length, uint8* BufferPtr);
Std_ReturnType EthIf_SwitchGetCfgDataInfo(uint8 SwitchIdx, uint32* DataSizePtr, uint32* DataAdressPtr);
Std_ReturnType EthIf_SwitchPortGetMaxFIFOBufferFillLevel(uint8 SwitchPortIdx,
	uint8 PortIdx, uint8 SwitchPortEgressFifoIdx, uint32* SwitchPortEgressFifoBufferLevelPtr);
Std_ReturnType EthIf_TransceiverGetMacMethod(uint8* TrcvIdx, EthTrcv_MacMethodType* MacModePtr);
Std_ReturnType EthIf_EthGetSpiStatus(uint8* CtrlIdx, Eth_SpiStatusType* SpiStatusPtr);

// Callback notifications
void EthIf_RxIndication(uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast,
	const uint8* PhysAddrPtr, const Eth_DataType* DataPtr, uint16 LenByte);
void EthIf_TxConfirmation(uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result);
void EthIf_CtrlModeIndication(uint8 CtrlIdx, Eth_ModeType CtrlMode);
void EthIf_TrcvModeIndication(uint8 TrcvIdx, Eth_ModeType TrcvMode);
void EthIf_SwitchPortModeIndication(uint8 SwitchIdx, uint8 SwitchPortIdx, Eth_ModeType PortMode);
void EthIf_SleepIndication(uint8 TrcvIdx);

// Scheduled Functions
void EthIf_MainFunctionRx(void);
// void EthIf_MainFunction Rx_<Priority Processing  ShortName>(void);
void EthIf_MainFunctionTx(void);
void EthIf_MainFunctionState(void);

#if 0
void <User>_RxIndication(uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast,  const uint8* PhysAddrPtr, const uint8* DataPtr, uint16 LenByte);
void <UL>_TxConfirmation(uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result);
void <User>_TrcvLinkStateChg(uint8 CtrlIdx, EthTrcv_LinkStateType TrcvLinkState);
#endif

#endif