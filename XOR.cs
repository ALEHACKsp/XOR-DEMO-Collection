using System;
					
public class Program
{
	private static String Decrypt(String data)
    {
            byte[] org = System.Convert.FromBase64String(data);
            byte[] bkey = System.Text.Encoding.UTF8.GetBytes("LOL");
            int keycount = 0;
            for (int i = 0; i< org.Length; i++)
            {
                org[i] ^= bkey[keycount];
                keycount++;
                if (keycount >= bkey.Length)
                    keycount = 0;
				Console.WriteLine("Round Decrypt");
				Console.WriteLine(System.Text.Encoding.UTF8.GetString(org));
            }
            return System.Text.Encoding.UTF8.GetString(org);
    }
	private static String EncryptString(String data,String key = "LOL")
        {
            byte[] bdata = System.Text.Encoding.UTF8.GetBytes(data);
            byte[] bkey = System.Text.Encoding.UTF8.GetBytes(key);
            int keycount = 0;
            for (int i = 0; i < data.Length; i++)
            {
                bdata[i] ^= bkey[keycount];
                keycount++;
                if (keycount >= bkey.Length)
                    keycount = 0;
				Console.WriteLine("Round Encrypt");
				Console.WriteLine(System.Text.Encoding.UTF8.GetString(bdata));
            }

            return System.Convert.ToBase64String(bdata);
        }
	
	public static void Main()
	{
		String data = EncryptString("Hello World");
		Console.WriteLine(data);
		Console.WriteLine(Decrypt(data));
	}
}
