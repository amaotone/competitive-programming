fun main(args: Array<String>) {
    var (a, b, c, d) = readLine()!!.map { it.toString().toInt() }
    for (op1 in arrayOf(-1, 1)) {
        for (op2 in arrayOf(-1, 1)) {
            for (op3 in arrayOf(-1, 1)) {
                if (a + op1 * b + op2 * c + op3 * d == 7) {
                    println("$a${if (op1 == 1) "+" else "-"}$b${if (op2 == 1) "+" else "-"}$c${if (op3 == 1) "+" else "-"}$d=7")
                    return
                }
            }
        }
    }
}