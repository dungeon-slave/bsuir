namespace Лаба1
{
    class ColumnCipher: VigenereCipher
    {
        void DeleteSymbols(ref string Str)
        {
        
            int i = 0, len = Str.Length;
            while(i < len)
            {
                if (!((Str[i] >= 'А' && Str[i] <= 'Я') || Str[i] == 'Ё'))
                {
                    Str = Str.Remove(i, 1);
                    len--;
                }
                else
                {
                    i++;
                }
            }
        }
        public ColumnCipher(string PlainText, string Key): base(PlainText, Key)
        {
            DeleteSymbols(ref this.PlainText);
            DeleteSymbols(ref this.Key);
        }
        protected override void KeyGeneration(string Source, ref int pos)
        {
            int min = 0,
                currsymb, 
                minsymb = SearchSymbol(Source, min), 
                possymb = SearchSymbol(Source, pos);

            for(int i = 0, len = Source.Length; i < len; i++)
            {
                currsymb = SearchSymbol(Source, i);
                if (currsymb < minsymb || (possymb >= minsymb ))
                {
                    if (pos == -1 || (currsymb >= possymb && i != pos))
                    {
                        if (pos != -1 && currsymb == possymb && i < pos) { continue; }
                        min = i;
                        minsymb = SearchSymbol(Source, min);
                        if (minsymb == possymb) { break; }
                    }
                }
            }
            pos = min; 
        }
        public override string Encryption(int type)
        {
            int keylen   = Key.Length,
                plainlen = PlainText.Length,
                j        = 0, 
                tmp      = 0;
            ref int refj   = ref j,
                    reftmp = ref tmp;
             
            if (type == -1)
            {
                refj   = ref tmp;
                reftmp = ref j;
            }

            char[] Cipher = new char[plainlen];

            for (int i = 0, pos = -1; i < keylen; i++)
            {
                KeyGeneration(Key, ref pos);
                tmp = pos;
                while (tmp < plainlen)
                {
                    if ((PlainText[j] >= 'А' && PlainText[j] <= 'Я') || PlainText[j] == 'Ё')
                    { Cipher[refj] = PlainText[reftmp]; }
                    j++;
                    tmp += keylen;
                }
            }

            return new string(Cipher);
        }
    }
}
