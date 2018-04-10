fun main(args: Array<String>) {
    var (A, B) = readLine()!!.split(" ").map{it.toInt()}
    val S = readLine()!!
    if (Regex("""\d{$A}-\d{$B}""").matches(S)) println("Yes")
    else println("No")
}
