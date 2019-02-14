static void toto(void)
{
    int i = 0;

    i = i + i;
}

int main(void)
{
    int i = 0;

    while (i < 1000) {
        i++;
        toto();
    }
}