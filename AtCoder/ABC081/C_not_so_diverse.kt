fun main(args: Array<String>) {
    val (N, K) = readLine()!!.split(" ").map { it.toInt() }
    val ans = readLine()!!.split(" ").map { it.toInt() }
            .groupBy { it }
            .map { it.value.count() }
            .sortedDescending()
            .filterIndexed { ind, v -> ind >= K }
            .sum()
    println(ans)
}
