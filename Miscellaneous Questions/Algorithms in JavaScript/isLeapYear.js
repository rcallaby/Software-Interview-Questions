//This is a solution in JavaScript where given a year you can determine if it is a leap year or not

function isLeapYear(year) {
    // A leap year occurs on any year evenly divisible by 4
    // but not on a century unless it is divisible by 400
    if (year % 4 === 0) {
        if (year % 100 === 0) {
            if (year % 400 === 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}