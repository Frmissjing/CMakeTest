#include "keyfile_api.h"

#define STORAGEDIR "../Keyfile"
#define SETTINGS_STORE "radiosetting"

GKeyFile *storage_open(const char *imsi, const char *store)
{
    GKeyFile *keyfile;
    char *path;

    if (store == NULL)
        return NULL;

    if (imsi)
        path = g_strdup_printf(STORAGEDIR "/%s/%s", imsi, store);
    else
        path = g_strdup_printf(STORAGEDIR "/%s", store);

    keyfile = g_key_file_new();

    if (path) {
        g_key_file_load_from_file(keyfile, path, 0, NULL);
        g_free(path);
    }

    return keyfile;
}

void print_test()
{
    char *path;
    path = g_strdup_printf(STORAGEDIR "/%s", SETTINGS_STORE);
    printf("print_test %s.", path);
}