using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'breakingRecords' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY scores as parameter.
     */

    public static List<int> breakingRecords(List<int> scores)
    {
        int minimumBand = 0;
        int maximumBand = 0;
        
        int minimumBreakScore = 0;
        int maximumBreakScore = 0;
        
        var distinctScoreValues = scores.Distinct().ToArray();
        minimumBand = distinctScoreValues[0];
        maximumBand = distinctScoreValues[0];
        
        for(int i = 1; i < distinctScoreValues.Count(); i++){
            var score = distinctScoreValues[i];
            if(score < minimumBand) {
                minimumBand = score;                
                minimumBreakScore++;
            }
            else if(score > maximumBand){
                maximumBand = score;                
                maximumBreakScore++;
            }
        }
        return new List<int>(){maximumBreakScore, minimumBreakScore};
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> scores = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(scoresTemp => Convert.ToInt32(scoresTemp)).ToList();

        List<int> result = Result.breakingRecords(scores);

        textWriter.WriteLine(String.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
