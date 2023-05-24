namespace Calculator;

public class Expression
{
    private int augend;
    private int addend;

    public Expression(int augend, int addend)
    {
        this.addend = addend;
        this.augend = augend;
    }

    public int Sum()
    {
        return augend + addend;
    }

    public int Subtract()
    {
        return augend - addend;
    }

    public int Multiply()
    {
        return augend * addend;
    }
}