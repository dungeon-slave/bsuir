namespace Лаба1
{
    class VigenereCipher
    {
        protected string PlainText, Key;
        string CipherText;
        readonly char[] Alphabet = {'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П',
                                   'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я'};
        public VigenereCipher(string PlainText, string Key)
        {
            this.PlainText = PlainText.ToUpper();
            this.Key       = Key.ToUpper();
        }

        protected int SearchSymbol(string Str, int pos)
        {
            if (pos != -1)
            {
                for (int i = 0; i <= 32; i++)
                {
                    if (Alphabet[i] == Str[pos])
                    {
                        return i;
                    }
                }
            }
            return -1;
        }
        protected virtual void KeyGeneration(string Source, ref int pos)
        {
            while (!((Source[pos] >= 'А' && Source[pos] <= 'Я') || Source[pos] == 'Ё')) { pos++; }
            Key += Source[pos];
        }
        public virtual string Encryption(int type)
        {
            int symbpos;
            for (int i = 0, j = 0, k = 0, len = PlainText.Length; i < len; i++)
            {
                if ((PlainText[i] >= 'А' && PlainText[i] <= 'Я') || PlainText[i] == 'Ё')
                {
                    if (Key.Length == j)
                    {
                        if (type == 1)
                        {
                            KeyGeneration(PlainText, ref k);
                        }
                        else
                        {
                            KeyGeneration(CipherText, ref k);
                        }
                        k++;
                    }
                    symbpos = SearchSymbol(PlainText, i) + type * SearchSymbol(Key, j);
                    if (symbpos > 32 || symbpos < 0)
                    {
                        symbpos -= type * 33;
                    }
                    CipherText += Alphabet[symbpos];
                    j++;
                }
                else
                {
                    CipherText += PlainText[i];
                }
            }

            return CipherText;
        }
    }
}
