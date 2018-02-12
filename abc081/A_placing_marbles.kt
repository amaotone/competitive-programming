fun main(args: Array<String>) {
    val s = readLine()!!
    var cnt = 0
    for (c in s) {
        if (c == '1') cnt++
    }
    println(cnt)
}
