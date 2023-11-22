#include <common.h>

static const char *default_en_list[] = { "911", "112", "999", "333", NULL };
static const char *default_en_list_no_sim[] = { "119", "118", "999", "110",
						"08", "000", NULL };


static void display_key(gpointer key, gpointer value,
                            gpointer user_data)
{
    const char *_key = (const char *) key;
    const char *_value = (const char *) value;

    g_assert (_key != NULL);

    printf ("%s\n", _key);
    return;
}

static void add_to_en_list(GHashTable *ghashtable, char **list)
{
	int i = 0;

	while (list[i])
		g_hash_table_insert(ghashtable, g_strdup(list[i++]), NULL);
}

void ghashtable_test1(void) {

	GSList* list = NULL;
    GHashTable *en_list = NULL; 

    printf("\n--------------run %s ----------------\n", __FUNCTION__);
 

	en_list = g_hash_table_new_full(g_str_hash, g_str_equal,
							g_free, NULL);

	/*
	 * Start out with the 22.101 mandated numbers, if we have a SIM and
	 * the SIM contains EFecc, then we update the list once we've read them
	 */
	add_to_en_list(en_list, (char **) default_en_list_no_sim);
	add_to_en_list(en_list, (char **) default_en_list);

    g_hash_table_foreach(en_list, display_key, NULL);

	printf("\n-----------------end %s-------------------\n",__FUNCTION__);
 
	return;
}




