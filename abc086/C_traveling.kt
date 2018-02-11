fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val (t, x, y) = Triple(0, 0, 0)
    for (i in (1..n)) {
        val (tt, xx, yy) = readLine()!!.split(" ").map{ it.toInt() }
        val dt = tt - t
        val dx = Math.abs(x-xx)
        val dy = Math.abs(y-yy)
        if ((dx + dy > dt) || ((dx+dy-dt)%2!=0)) {
            println("No")
            return
        }
    }
    println("Yes")
    return
}