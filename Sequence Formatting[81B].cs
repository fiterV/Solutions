using System;
using System.Collections.Generic;
namespace Application
{
	public class Solution
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine ();
			for (int i = s.IndexOf ("  "); i != -1; i = s.IndexOf ("  "))
				s = s.Remove (i + 1, 1);
			string bac = "";
			for (int i = 0; i < s.Length; i++)
				if (!(s [i] == ' ' && (i == 0 || i == s.Length - 1 || s [i - 1] < '0' || s [i - 1] > '9' || s [i + 1] < '0' || s [i + 1] > '9')))
					bac += s [i];
			s = bac;
			for (int i = 0; i < s.Length - 1; i++)
				if (s [i] == ',')
					s = s.Insert (i + 1, " ");
			for (int i = s.IndexOf ("..."); i != -1; i = s.IndexOf ("...", i + 3)) {
				if (i > 0 && s [i - 1] != ' ') {
					s = s.Insert (i, " ");
					i++;
				}
				if (i + 3 >= s.Length)
					break;
			}
			Console.WriteLine (s);
		}
	}
}

