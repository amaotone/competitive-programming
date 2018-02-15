fun main(args: Array<String>) {
    var N = readLine()!!.toInt()
    var A = readLine()!!.split(" ").map { it.toInt() }
    when {
    // 非負だけ
        A.filter { it >= 0 }.size == N -> {
            println("${N - 1}")
            for (i in 1..N - 1) {
                println("$i ${i + 1}")
            }
        }
    // 非正だけ
        A.filter { it <= 0 }.size == N -> {
            println("${N - 1}")
            for (i in N - 1 downTo 1) {
                println("${i + 1} $i")
            }
        }
    // 混在
        else -> {
            val max = A.withIndex().maxBy { it.value }!!
            val min = A.withIndex().minBy { it.value }!!
            when {
                Math.abs(max.value) >= Math.abs(min.value) -> {
                    println("${2 * N - 1}")
                    for (i in 1..N) {
                        println("${max.index + 1} $i")
                    }
                    for (i in 1..N - 1) {
                        println("$i ${i + 1}")
                    }
                }
                else -> {
                    println("${2 * N - 1}")
                    for (i in 1..N) {
                        println("${min.index + 1} $i")
                    }
                    for (i in N - 1 downTo 1) {
                        println("${i + 1} $i")
                    }
                }
            }
        }
    }
}
