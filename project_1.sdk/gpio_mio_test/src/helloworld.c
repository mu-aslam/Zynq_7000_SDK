

/***************************** Include Files ********************************/

#include "xparameters.h"
#include "xgpiops.h"
#include "xstatus.h"
#include <xil_printf.h>
#include "sleep.h"
/************************** Variable Definitions **************************/

/*
 * The following are declared globally so they are zeroed and can be
 * easily accessible from a debugger.
 */
XGpioPs Gpio;	/* The driver instance for GPIO Device. */

XGpioPs_Config *ConfigPtr;
/*****************************************************************************/

int main(void)
{
	int Status;
	u32 InputData;

	/* Initialize the GPIO driver. */
	ConfigPtr = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID);
	Status = XGpioPs_CfgInitialize(&Gpio, ConfigPtr,
					ConfigPtr->BaseAddr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//GPIO_PS
	XGpioPs_SetDirectionPin(&Gpio, 50, 0);
	XGpioPs_SetOutputEnablePin(&Gpio, 50, 0);
	XGpioPs_SetDirectionPin(&Gpio, 7, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 7, 1);
	//PMOD//////////
	//output
	XGpioPs_SetDirectionPin(&Gpio, 0, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 0, 1);
	XGpioPs_SetDirectionPin(&Gpio, 9, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 9, 1);
	XGpioPs_SetDirectionPin(&Gpio, 10, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 10, 1);
	XGpioPs_SetDirectionPin(&Gpio, 11, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 11, 1);
    //output
	XGpioPs_SetDirectionPin(&Gpio, 12, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 12, 1);
	XGpioPs_SetDirectionPin(&Gpio, 13, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 13, 1);
	XGpioPs_SetDirectionPin(&Gpio, 14, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 14, 1);
	XGpioPs_SetDirectionPin(&Gpio, 15, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, 15, 1);


	while(1){
		// PS_GPIO
		InputData = XGpioPs_ReadPin(&Gpio, 50);
		usleep(100);
		XGpioPs_WritePin(&Gpio, 7, InputData);
		// PMOD E
		XGpioPs_WritePin(&Gpio, 0, 1);
		XGpioPs_WritePin(&Gpio, 9, 1);
		XGpioPs_WritePin(&Gpio, 10,1);
		XGpioPs_WritePin(&Gpio, 11,1);
		XGpioPs_WritePin(&Gpio, 12,0);
		XGpioPs_WritePin(&Gpio, 13,0);
		XGpioPs_WritePin(&Gpio, 14,0);
		XGpioPs_WritePin(&Gpio, 15,0);
		usleep(100);
		XGpioPs_WritePin(&Gpio, 0, 0);
		XGpioPs_WritePin(&Gpio, 9, 0);
		XGpioPs_WritePin(&Gpio, 10,0);
		XGpioPs_WritePin(&Gpio, 11,0);
		XGpioPs_WritePin(&Gpio, 12,1);
		XGpioPs_WritePin(&Gpio, 13,1);
		XGpioPs_WritePin(&Gpio, 14,1);
		XGpioPs_WritePin(&Gpio, 15,1);
		//printf("yess");
	}
	return XST_SUCCESS;
}



