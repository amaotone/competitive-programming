fun main(args: Array<String>) {
    val N = readLine()!!
    var sum = 0
    for (c in N) {
        sum += c.toString().toInt()
    }
    println(if (N.toInt() % sum == 0) "Yes" else "No")
}
