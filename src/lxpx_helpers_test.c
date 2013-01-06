
/*
 * 2012 Even Brenden
 */

#include <stdio.h>
#include "billigtest.h"
#include "lxpx_helpers.h"

static void printpacked (t_packed_value *p_value)
{
	printbin (p_value->byte_0, 8);
	printf("\n");
	printbin (p_value->byte_1, 8);
	printf("\n");
	printbin (p_value->byte_2, 8);
	printf("\n");
}

void test_ones ()
{
	char navn[] = "test_ones";

	t_packed_value p_value;
	int up_value = 0xFFFF;

	unpacked_to_packed (&p_value, up_value);

	sjekk_sann (p_value.byte_0 == 0x03, navn);
	sjekk_sann (p_value.byte_1 == 0x7F, navn);
	sjekk_sann (p_value.byte_2 == 0x7F, navn);
}

void test_zeroes ()
{
	char navn[] = "test_zeroes";

	t_packed_value p_value;
	int up_value = 0x0000;

	unpacked_to_packed (&p_value, up_value);

	sjekk_sann (p_value.byte_0 == 0x00, navn);
	sjekk_sann (p_value.byte_1 == 0x00, navn);
	sjekk_sann (p_value.byte_2 == 0x00, navn);
}

void test_msb_everyotherbit()
{
	char navn[] = "test_msb_everyotherbit";

	t_packed_value p_value;
	int up_value = 0xAA00;

	unpacked_to_packed (&p_value, up_value);

	sjekk_sann (p_value.byte_0 == 0x02, navn);
	sjekk_sann (p_value.byte_1 == 0x00, navn);
	sjekk_sann (p_value.byte_2 == 0x2A, navn);
}

void test_lsb_everyotherbit()
{
	char navn[] = "test_lsb_everyotherbit";

	t_packed_value p_value;
	int up_value = 0x00AA;

	unpacked_to_packed (&p_value, up_value);

	sjekk_sann (p_value.byte_0 == 0x01, navn);
	sjekk_sann (p_value.byte_1 == 0x2A, navn);
	sjekk_sann (p_value.byte_2 == 0x00, navn);
}

void test_46547()
{
	char navn[] = "test_lsb_everyotherbit";

	t_packed_value p_value;
	int up_value = 0xB5D3;

	unpacked_to_packed (&p_value, up_value);

	sjekk_sann (p_value.byte_0 == 0x03, navn);
	sjekk_sann (p_value.byte_1 == 0x53, navn);
	sjekk_sann (p_value.byte_2 == 0x35, navn);
}
int main ()
{
	test_zeroes();
	test_ones();
	test_msb_everyotherbit();
	test_lsb_everyotherbit();
	test_46547();

	return 0;
}
