#include "common.h"

typedef struct glist_data_st
{
	/* data */
	int id;
	char *str;
}Tglist_data;

static Tglist_data* glist_data_new(int id, const char *str) {
	Tglist_data *glist_data = g_try_new0(Tglist_data, 1);
	glist_data->id = id;
	glist_data->str = g_strdup(str);
	return glist_data;
}

static void glist_data_detroy(Tglist_data **glist_data) {
	g_free((*glist_data)->str);
	g_free(*glist_data);
	*glist_data = NULL;
	return;
}

void display_glist_data(GSList *list)
{
	GSList *iterator = NULL;
	g_printf("------------start %s--------------\n", __FUNCTION__);
	for (iterator = list; iterator; iterator = iterator->next) {
		g_printf("id=%d,str=%s\n",((Tglist_data*)iterator->data)->id, ((Tglist_data*)iterator->data)->str);
	}
	g_printf("------------end %s--------------\n", __FUNCTION__);
}

gint glist_data_compare_by_id(gconstpointer a, gconstpointer b)
{
	int id = *(int*)a;
	const Tglist_data *cb = b;

	if (id < cb->id)
		return -1;

	if (id > cb->id)
		return 1;

	return 0;
}

gint glist_data_compare(gconstpointer a, gconstpointer b)
{
	const Tglist_data *ca = a;
	const Tglist_data *cb = b;

	if (ca->id < cb->id)
		return -1;

	if (ca->id > cb->id)
		return 1;

	return 0;
}

void display_list(GSList *list)
{
	GSList *iterator = NULL;
 
	for (iterator = list; iterator; iterator = iterator->next) {
		g_printf("%s ", (char*)iterator->data);
	}
	g_printf("\n");
}

void glist_test1(void)
{
    GSList* list = NULL;
 
	printf("\n--------------run %s ----------------\n", __FUNCTION__);
 
	list = g_slist_append(list, "first");
	list = g_slist_append(list, "second");
	list = g_slist_append(list, "third");
	
	g_printf("The list is now %d items long\n", g_slist_length(list));
 
	list = g_slist_remove(list, "second");
	list = g_slist_remove_all(list, "third");
	g_printf("The list is now %d items long\n", g_slist_length(list));
	g_slist_free(list);
 
	printf("\n-----------------end %s-------------------\n", __FUNCTION__);
    return;
}

void glist_test2(void)
{
    GSList* list = NULL;
 
	printf("\n--------------run %s ----------------\n", __FUNCTION__);
 
	list = g_slist_append(list, "first");
	list = g_slist_append(list, "second");
	list = g_slist_append(list, "third");
	
	g_printf("The list is now %d items long\n", g_slist_length(list));
 

	g_slist_free(list);
 
	printf("\n-----------------end %s-------------------\n", __FUNCTION__);
    return;
}

void glist_test3(void) {
 
	printf("\n--------------run %s ----------------\n", __FUNCTION__);
 
	GSList* list1 = NULL;
	list1 = g_slist_append(list1, "first");
	list1 = g_slist_append(list1, "second");
 
	GSList * list2 = NULL;
	list2 = g_slist_append(list2, "third");
	list2 = g_slist_append(list2, "fourth");
	
	GSList * both = g_slist_concat(list1, list2); //连接两个表
	display_list(both);
 
	g_printf("The third item in the concatenated list is '%s'\n", (char*)g_slist_nth_data(both, 2));
 
 
	GSList * reversed = g_slist_reverse(both); //反转一个表
	g_printf("The first item in the reversed list is '%s'\n", (char*)reversed->data);
 
	display_list(reversed);
 
	g_slist_free(reversed);
 
	printf("\n-----------------end %s-------------------\n",__FUNCTION__);
 
	return;
}

void glist_test4(void) {
 
	printf("\n--------------run %s ----------------\n", __FUNCTION__);
 
	GSList* list = NULL;
	list = g_slist_prepend(list, "first");
	list = g_slist_prepend(list, "second");
 
	display_list(list);

 	list = g_slist_prepend(list, "third");
	display_list(list);

    GSList * reversed = g_slist_reverse(list); //反转一个表
	g_printf("The first item in the reversed list is '%s'\n", (char*)reversed->data);

	display_list(reversed);

	printf("\n-----------------end %s-------------------\n",__FUNCTION__);
 
	return;
}

void glist_test5(void) {
 
	printf("\n--------------run %s ----------------\n", __FUNCTION__);
 
	GSList* list = NULL;
	Tglist_data data1 = {
		.id = 1,
		.str = "fisrt"
	};

	Tglist_data data2 = {
		.id = 2,
		.str = "second"
	};

	Tglist_data data2_1 = {
		.id = 2,
		.str = "second_first"
	};

	Tglist_data data3 = {
		.id = 3,
		.str = "third"
	};

	Tglist_data data4 = {
		.id = 4,
		.str = "four"
	};
	
	list = g_slist_append(list, &data1);
	list = g_slist_append(list, &data2);
 	list = g_slist_append(list, &data4);

	display_glist_data(list);

	list = g_slist_insert_sorted(list, &data3, glist_data_compare);

	display_glist_data(list);

	list = g_slist_insert_sorted(list, &data2_1, glist_data_compare);

	display_glist_data(list);

	printf("\n-----------------end %s-------------------\n",__FUNCTION__);
 
	return;
}

GSList* glist_test6_1(void){
	GSList *list = NULL;

	Tglist_data *data1 = glist_data_new(1, "first");
	Tglist_data *data2 = glist_data_new(2, "second");
	// Tglist_data *data3 = glist_data_new(3, "third");
	Tglist_data *data4 = glist_data_new(4, "four");

	list = g_slist_append(list, data1);
	list = g_slist_append(list, data2);
 	list = g_slist_append(list, data4);

	display_glist_data(list);

	// list = g_slist_insert_sorted(list, data3, glist_data_compare);

	// display_glist_data(list);

	return list;
}

void glist_test6(void) {

	printf("\n--------------start %s g_slist_remove------------\n", __FUNCTION__);

	GSList *list = glist_test6_1();
	GSList *node = NULL;
	int id = 3;

	//find node

	node = g_slist_find_custom(list, &id, glist_data_compare_by_id);

	if(node){
		Tglist_data *data = node->data;
		list = g_slist_remove_link(list, node);
		printf("node data id:%d, str=%s.\n", data->id, data->str);
		g_free(data);
		g_slist_free1(node);
	}

	display_glist_data(list);

	for(int i=1; i<5; i++)
	{
		node = g_slist_find_custom(list, &i, glist_data_compare_by_id);
		if(node){
			Tglist_data *data = node->data;
			list = g_slist_remove_link(list, node);
			printf("node data id:%d, str=%s.\n", data->id, data->str);
			g_free(data);
			g_slist_free1(node);
		}
	}	

	if(NULL == list){
		printf("list already not exist");
	}

	printf("\n-----------------end %s g_slist_remove-------------------\n",__FUNCTION__);
 
	return;
}

