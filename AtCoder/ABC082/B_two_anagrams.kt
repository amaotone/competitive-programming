fun main(args: Array<String>) {
    val s = String(readLine()!!.toCharArray().sortedArray())
    val t = String(readLine()!!.toCharArray().sortedArrayDescending())
    println(if (t > s) "Yes" else "No")
}
