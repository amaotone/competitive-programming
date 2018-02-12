fun main(args: Array<String>) {
    readLine()!!.toInt()
    val ans = readLine()!!.split(" ")
            .map { it.toInt() }
            .groupBy { it }
            .map { if (it.key > it.value.count()) it.value.count() else it.value.count() - it.key }
            .sum()
    println(ans)
}
