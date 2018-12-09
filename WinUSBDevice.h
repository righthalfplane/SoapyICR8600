/*
 * Icom ICR8600 SoapySDR Library
 *
 * Made in 2018 by D.Eliuseev dmitryelj@gmail.com
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
//
// Define below GUIDs
//
#include <initguid.h>
#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <winusb.h>
#include <usb.h>
#include <stdio.h>
#include <cfgmgr32.h>

#ifndef WINUSB_DEFINES
#define WINUSB_DEFINES

//
// Device Interface GUID.
// Used by all WinUsb devices that this application talks to.
// Must match "DeviceInterfaceGUIDs" registry value specified in the INF file.

//
// Icom IC-R8600 GUID: 68D5F5EE-B0E7-49FD-A0D5-5B10842656B7
//
DEFINE_GUID(GUID_DEVINTERFACE_WinUSB1, 0x68D5F5EE, 0xB0E7, 0x49FD, 0xA0,0xD5, 0x5B,0x10,0x84,0x26,0x56,0xB7);

// 
// Icom IC-R8600 Pipe endpoints IDs
//
#define PIPE_CONTROL_ID		0x02 
#define PIPE_RESPONSE_ID	0x88 
#define PIPE_IQ_ID			0x86 

typedef struct _DEVICE_DATA {
    BOOL                    HandlesOpen;
    WINUSB_INTERFACE_HANDLE WinusbHandle;
    HANDLE                  DeviceHandle;
    TCHAR                   DevicePath[MAX_PATH];
} DEVICE_DATA, *PDEVICE_DATA;

BOOL FindICR8600Device();
HRESULT OpenDevice(_Out_ PDEVICE_DATA DeviceData, _Out_opt_ PBOOL FailureDeviceNotFound);
VOID	CloseDevice(_Inout_ PDEVICE_DATA DeviceData);

void ICR8600SetRemoteOn(WINUSB_INTERFACE_HANDLE hDeviceHandle);
void ICR8600SetRemoteOff(WINUSB_INTERFACE_HANDLE hDeviceHandle);
BOOL ICR8600SetSampleRate(WINUSB_INTERFACE_HANDLE hDeviceHandle, ULONG sampleRate);
BOOL ICR8600SetFrequency(WINUSB_INTERFACE_HANDLE hDeviceHandle, ULONG frequency);
BOOL ICR8600SetAntenna(WINUSB_INTERFACE_HANDLE hDeviceHandle, int antennaIndex);
ULONG ICR8600ReadPipe(WINUSB_INTERFACE_HANDLE hDeviceHandle, PUCHAR Buffer, ULONG BufferLength);

#endif