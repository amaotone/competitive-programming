fun main(args: Array<String>) {
    val S = readLine()!!
    val n = S.length
    var ans = S.length
    var prev = S[0]
    for ((k, c) in S.withIndex()) {
        if (c != prev) {
            val t = arrayOf(k, n - k).max()!!
            ans = arrayOf(ans, t).min()!!
        }
        prev = c
    }
    println(ans)
}
