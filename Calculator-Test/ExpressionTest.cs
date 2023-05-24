using Calculator;

namespace Calculator_Test;

public class ExpressionTest
{
    [Test]
    public void Sum_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Sum(new Integer(1), new Integer(1));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(2));
    }

    [Test]
    public void Subtract_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Subtract(new Integer(5), new Integer(2));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(3));
    }

    [Test]
    public void Multiply_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Multiply(new Integer(5), new Integer(2));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(10));
    }

    [Test]
    public void Divide_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Divide(new Integer(4), new Integer(2));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(2));
    }

    [Test]
    public void Divide_DividedByZero_ThrowsException()
    {
        // Arrange
        IExpression expression = new Divide(new Integer(4), new Integer(0));
        
        // Act

        // Assert
        Assert.Catch(() => {expression.Calculate();});
    }

    [Test]
    public void Sum_ThreeNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression1 = new Sum(new Integer(1), new Integer(1));
        IExpression expression2 = new Sum(expression1, new Integer(2));

        // Act
        var ret = expression2.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(4));
    }

    [Test]
    public void Integer_SingleNumber_ReturnsThatNumber()
    {
        // Arrange
        IExpression expression = new Integer(1);

        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(1));
    }

    [Test]
    public void Calculate_ComplexExpression_ReturnsValidNumber()
    {
        // Arrange
        IExpression two = new Integer(2);
        IExpression five = new Integer(5);
        IExpression sum = new Sum(two, five);
        IExpression subtract = new Subtract(five, two);
        IExpression multiply = new Multiply(five, two);

        IExpression exp1 = new Multiply(multiply, subtract);
        IExpression exp2 = new Subtract(exp1, multiply);
        IExpression exp3 = new Sum(sum, exp2);

        // Act
        var ret = exp3.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(27));
    }
}