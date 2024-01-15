/*
 * Created on Mon Jan 23 2023 9:46:46 PM
 *
 * The MIT License (MIT)
 * Copyright (c) 2023 Aananth C N
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
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
#include <EthIf.h>
#include <os_api.h> // for LOG_DBG()


#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(EthIf, LOG_LEVEL_DBG);



void EthIf_Init(const EthIf_ConfigType* CfgPtr) {
	LOG_DBG("Init complete!");
}


// Provides access to a transmit buffer of the specified Ethernet controller
BufReq_ReturnType EthIf_ProvideTxBuffer(uint8 CtrlIdx, Eth_FrameType FrameType,
	uint8 Priority,  Eth_BufIdxType* BufIdxPtr, uint8** BufPtr, uint16* LenBytePtr) {

	return Eth_ProvideTxBuffer(CtrlIdx, Priority, BufIdxPtr, BufPtr, LenBytePtr);
}


Std_ReturnType EthIf_Transmit(uint8 CtrlIdx, Eth_BufIdxType BufIdx, Eth_FrameType FrameType,
		boolean TxConfirmation,  uint16 LenByte, const uint8* PhysAddrPtr) {
	Std_ReturnType retc = E_NOT_OK;

	return retc;
}


/////////////////////////////
// Callback functions
void EthIf_RxIndication(uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast,
	const uint8* PhysAddrPtr, const Eth_DataType* DataPtr, uint16 LenByte) {

}


void EthIf_TxConfirmation(uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result) {

}


/////////////////////////////
// Scheduled Function
void EthIf_MainFunctionRx(void) {
	uint8 ctrlIdx = 0;
	uint8 fifoIdx = 0; 
	Eth_RxStatusType RxStatusPtr;

	Eth_Receive(ctrlIdx, fifoIdx, &RxStatusPtr);
}


void EthIf_MainFunctionTx(void) {
	Std_ReturnType tx_code;
	uint8 ctrlIdx = 0;
	Eth_BufIdxType bufIdx;
	Eth_FrameType frameType;
	boolean txConfirmation = FALSE;
	uint16 lenByte = 1;
	const uint8* PhysAddrPtr = NULL;
	
	tx_code = Eth_Transmit(ctrlIdx, bufIdx, frameType, txConfirmation, lenByte, PhysAddrPtr);
}


void EthIf_MainFunctionState(void) {

}