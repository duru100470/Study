namespace Calculator;

public abstract class Expression
{
    protected int augend;
    protected int addend;

    public Expression(Expression? augend, Expression? addend)
    {
        this.augend = augend?.Calculate() ?? 0;
        this.addend = addend?.Calculate() ?? 0;
    }

    public abstract int Calculate();
}

public class Sum : Expression
{
    public Sum(Expression augend, Expression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend + addend;
    }
}

public class Subtract : Expression
{
    public Subtract(Expression augend, Expression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend - addend;
    }
}

public class Multiply : Expression
{
    public Multiply(Expression augend, Expression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend * addend;
    }
}

public class Integer : Expression
{
    public Integer(int number) : base(null, null)
    {
        this.augend = number;
    }

    public override int Calculate()
    {
        return augend;
    }
}