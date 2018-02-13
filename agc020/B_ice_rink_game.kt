fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map { it.toInt() }
    var min = 2L
    var max = 2L
    for (i in N - 1 downTo 0) {
        if (A[i] > min || min > max) {
            println("-1")
            return
        }
        max += A[i] - 1
        if (i == 0) break
        max = max / A[i - 1] * A[i - 1]
        min = ((min - 1) / A[i - 1] + 1) * A[i - 1]
    }
    println("$min $max")
}
