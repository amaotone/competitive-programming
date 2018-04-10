fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    var arr = IntArray(N, {0})
    for (i in 0..N-1) {
        arr[i] = readLine()!!.toInt()
    }
    println(arr.toSet().size)
}
