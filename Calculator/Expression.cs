namespace Calculator;

public interface IExpression
{
    int Calculate();
}

public abstract class Operator
{
    protected int augend;
    protected int addend;

    public Operator(IExpression augend, IExpression addend)
    {
        this.augend = augend.Calculate();
        this.addend = addend.Calculate();
    }

    public abstract int Calculate();
}

public class Sum : Operator, IExpression
{
    public Sum(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend + addend;
    }
}

public class Subtract : Operator, IExpression
{
    public Subtract(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend - addend;
    }
}

public class Multiply : Operator, IExpression
{
    public Multiply(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend * addend;
    }
}

public class Integer : IExpression
{
    private int number;

    public Integer(int number)
    {
        this.number = number;
    }

    public int Calculate()
    {
        return number;
    }
}