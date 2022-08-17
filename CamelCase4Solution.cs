using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {
    static void Main(String[] args) {
        string line;
        List<string> input = new List<string>();
        while ((line = Console.ReadLine()) != null && line != "") {
            input.Add(line);
        }
        
        for(int i = 0; i < input.Count; i++){
            var splittedInput = input[i].Split(';');
            var type = splittedInput[1];
            var content = splittedInput[2];
            
            string result = "";
            switch(splittedInput[0]){
                case "S":
                result = Split(type, content);
                break;
                case "C":
                result = Combine(type, content);
                break;
            }
            Console.WriteLine(result);
        }      
    }
    
    public static string Split(string type, string content){
        string[] words = new string[]{};
        switch(type){
            case "M":
                words = SplitByUpperCase(content).Select(x => x.ToLower()).ToArray();
                return string.Join(' ', words);
            case "V":
                words = SplitByUpperCase(content).Select(x => x.ToLower()).ToArray();
                return string.Join(' ', words);
            case "C":
                words = SplitByUpperCase(content).Select(x => x.ToLower()).ToArray();
                return string.Join(' ', words);
            default: throw new Exception();
        }
    }
    
    public static string[] SplitByUpperCase(string content){
        List<string> words = new List<string>();
        int lastPos = 0;
        for(int i = 1; i < content.Length; i++){
            if(Char.IsUpper(content[i])){
                words.Add(content.Substring(lastPos, i-lastPos));
                lastPos = i;
            }
            else if(i == content.Length - 1){
                words.Add(content.Substring(lastPos, i + 1 - lastPos).Replace("()",""));
            }
        }
        
        return words.ToArray();
    }
    
    public static string Combine(string type, string content){
        var words = content.Split(' ').Select(x => x).ToArray();
        
        switch(type){
            case "M":
                return ConcatWordsToCamelCase(words) + "()";
            case "V":
                return ConcatWordsToCamelCase(words);
            case "C" : 
            var firstWordAsCharArray = words[0].ToCharArray();
            firstWordAsCharArray[0] = Char.ToUpper(firstWordAsCharArray[0]);
            words[0] = new string(firstWordAsCharArray);
            return ConcatWordsToCamelCase(words);
            default: throw new Exception();
        }
    }
    
    private static string ConcatWordsToCamelCase(string [] words){
        var wordsAsCharArray = words.Select(x => x.ToCharArray()).ToArray();
        var result = new string(wordsAsCharArray[0]);
         
            for(int i = 1; i < wordsAsCharArray.Count(); i++){
                wordsAsCharArray[i][0] = Char.ToUpper(wordsAsCharArray[i][0]);
                result = string.Concat(result, new string(wordsAsCharArray[i]));
            }
        return result;
    }
}
