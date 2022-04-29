/*
 * NM_Generator.c
 *
 *  Created on: Apr 29, 2022
 *      Author: Youssef Alarnaouty
 */

#include <stdio.h>

#define SRC_NODE_ID 		0x10u
#define FRAME_SIZE			8				/* CAN Frame Size */
#define CVB 				0x40u			/* Enable PNI bit only */
#define PNC_VECTOR_OFFSET 	2				/* Bytes 0 and 1 are reserved for CBV and Source Node ID */





/*	 Function: enable_PNCs
 * 	 ----------------------------
 *   Functionality: Sets the bits corresponding to certain PNCs in the NM frame.
 *   Input : The array corresponding to the NM Frame.
 *	 Output: No direct return value, changes the user data bytes in the NM frame array.
 *   Remarks: The function requests at runtime from the user the PNC IDs to be enabled.
 */
void enable_PNCs(unsigned char NM_Frame[]){
	int enabled_PNC_count;
	int temp,bytePosition;
	printf("Enter the number of PNCs to be enabled: ");
	fflush(stdout);
	scanf("%d", &enabled_PNC_count);
	printf("\n");
	fflush(stdout);

	if(enabled_PNC_count == 0)
		return;
	printf( "Enter the PNC IDs to be enabled(Valid From %d->%d)\n ",PNC_VECTOR_OFFSET*8,(FRAME_SIZE)*8-1);
	fflush(stdout);
	for (int i = 0; i < enabled_PNC_count; i++) {
		scanf("%d", &temp);
		bytePosition  = (temp / 8u);
		if((bytePosition-PNC_VECTOR_OFFSET < 0) || (bytePosition > FRAME_SIZE-1)){
			printf("%d is an invalid PNC Id, must be between %d and %d \n",temp,PNC_VECTOR_OFFSET*8,(FRAME_SIZE)*8-1);
			fflush(stdout);
			i--;
		}
		else
			NM_Frame[(temp / 8u)] |= ((1 << (temp % 8u)&0xFF));
	}
}





/*	 Function: disable_PNCs
 * 	 ----------------------------
 *   Functionality: Clears the bits corresponding to certain PNCs in the NM frame.
 *   Input : The array corresponding to the NM Frame.
 *	 Output: No direct return value, changes the user data bytes in the NM frame array.
 *   Remarks: The function requests at runtime from the user the PNC IDs to be disabled.
 */
void disable_PNCs(unsigned char NM_Frame[]){
	int disabled_PNC_count;
	int temp,bytePosition;

	printf("Enter the number of PNCs to be enabled: ");
	fflush(stdout);
	scanf("%d", &disabled_PNC_count);
	printf("\n");
	fflush(stdout);

	if(disabled_PNC_count == 0)
		return;

	printf( "Enter the PNC IDs to be enabled(Valid From %d->%d)\n ",PNC_VECTOR_OFFSET*8,(FRAME_SIZE)*8-1);
	fflush(stdout);

	for (int i = 0; i < disabled_PNC_count; i++) {
		scanf("%d", &temp);
		bytePosition  = (temp / 8u);

		/* Check if the ID is not within bounds*/
		if((bytePosition-PNC_VECTOR_OFFSET < 0) || (bytePosition > FRAME_SIZE-1)){
			printf("%d is an invalid PNC Id, must be between %d and %d \n",temp,PNC_VECTOR_OFFSET*8,(FRAME_SIZE)*8-1);
			fflush(stdout);
			i--;
		}
		else
			NM_Frame[(temp / 8u)] &= (~(1 << (temp % 8u)&0xFF));
	}

}





/*	 Function: print_Frame
 * 	 ----------------------------
 *   Functionality: Prints on the console a Frame as Hex bytes.
 *   Input : The array corresponding to the NM Frame.
 *	 Output: No direct return value, prints the frame on the screen as Hex bytes
 *   Remarks: None.
 */
void print_Frame(unsigned char NM_Frame[]){
	for (int i = 0; i < FRAME_SIZE; i++) {
			printf("%02x ",NM_Frame[i]);
		}
	printf("\n");
}






int main() {

	unsigned char NM_Frame[FRAME_SIZE] = { 0 };			/* Construct an empty frame */

	NM_Frame[0] = CVB & 0xFF;							/* Add CVB data to the first byte of frame */
	NM_Frame[1] = SRC_NODE_ID & 0xFF;					/* Add Source Node ID to the second byte of the frame */

	enable_PNCs(NM_Frame);
	printf("\nNM Frame after enabling PNCs: \n");
	print_Frame(NM_Frame);


	disable_PNCs(NM_Frame);
	printf("\nNM Frame after disabling PNCs: \n");
	print_Frame(NM_Frame);

	return 0;
}
